'''
  https://www.acmicpc.net/problem/17822
  구현 후에 간단한 BFS를 이용하면 풀리는 문제였다.
  처음에 문제를 잘못 읽어서 단계별로 계산하지않고, 최종상태만 두고서 계산하는 실수를 범했다.
  다행히 로직을 잘 나눠서 짠 덕분에 수정할 때, T로 제어되는 반복문의 block 영역만 조정해주는 것으로 해결을 했다.
  이렇게 바꾼 후에, 돌린 상태를 다음 회전의 초기값으로 설정하지않고 돌려서 답이 안나왔었다.
  이 부분도 그 부분만 추가했더니 정상적으로 작동하고 답을 얻을 수 있었다.
  
  문제를 똑바로 잘 읽어야겠다. 차근차근 읽고 푸는게 더 빠르게 푸는 법이라는 걸 항상 명심해야겠다.
'''
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
int main()
{
    int N = 0, M = 0, T = 0;
    int *spin, **pan, **afterSpin;
    int x = 0, d = 0, k = 0;
    scanf("%d %d %d", &N, &M, &T);
    pan = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        pan[i] = (int *)malloc(sizeof(int) * M);
    }
    afterSpin = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        afterSpin[i] = (int *)malloc(sizeof(int) * M);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d ", &pan[i][j]);
        }
    }

    for (int t = 0; t < T; t++)
    {
        scanf("%d %d %d", &x, &d, &k);
        spin = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
            spin[i] = 0;
        for (int i = x - 1; i < N; i += x)
        {
            if (d == 0)
                spin[i] = k;
            else
                spin[i] = (-1) * k;
        }

        for (int i = 0; i < N; i++)
        {
            spin[i] %= M;
            if (spin[i] > 0)
            {
                for (int j = M - k; j < M; j++)
                {
                    afterSpin[i][j - (M - k)] = pan[i][j];
                }
                for (int j = 0; j < M - k; j++)
                {
                    afterSpin[i][j + k] = pan[i][j];
                }
            }
            else if (spin[i] < 0)
            {
                for (int j = k; j < M; j++)
                {
                    afterSpin[i][j - k] = pan[i][j];
                }
                for (int j = 0; j < k; j++)
                {
                    afterSpin[i][M - k + j] = pan[i][j];
                }
            }
            else
            {
                for (int j = 0; j < M; j++)
                    afterSpin[i][j] = pan[i][j];
            }
        }
        /*
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                printf("%d ", afterSpin[i][j]);
            }
            printf("\n");
        }*/
        bool visited[51][51] = {
            false,
        };
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && afterSpin[i][j] != 0)
                {
                    int num = 1;
                    queue<pair<int, int>> q;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));

                    while (!q.empty())
                    {
                        int x = q.front().second;
                        int y = q.front().first;
                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int next_x = x + dx[dir];
                            int next_y = y + dy[dir];

                            if (next_x == M)
                                next_x = 0;
                            if (next_x == -1)
                                next_x = M - 1;
                            if (next_x < 0 || next_y < 0 || next_y >= N || next_x >= M || visited[next_y][next_x])
                                continue;
                            if (afterSpin[y][x] != afterSpin[next_y][next_x])
                                continue;

                            visited[next_y][next_x] = true;
                            q.push(make_pair(next_y, next_x));
                            num++;
                        }
                    }
                    if (num == 1)
                        visited[i][j] = false;
                }
            }
        }
        double avg = 0;
        int sum = 0, div = 0;
        bool flag = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[i][j])
                {
                    afterSpin[i][j] = 0;
                    flag = true;
                }
                sum += afterSpin[i][j];
                if (afterSpin[i][j] != 0)
                    div++;
            }
        }
        if (!flag)
        {
            avg = (double)sum / (double)div;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (afterSpin[i][j] != 0)
                    {
                        if (afterSpin[i][j] < avg)
                            afterSpin[i][j]++;
                        else if (afterSpin[i][j] > avg)
                            afterSpin[i][j]--;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                pan[i][j] = afterSpin[i][j];
            }
        }
        free(spin);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans += afterSpin[i][j];
        }
    }
    printf("%d", ans);
    return 0;
}
