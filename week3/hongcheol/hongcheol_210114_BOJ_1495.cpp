'''
https://www.acmicpc.net/problem/1495
DP문제
문제에 분명히 마지막 곡의 불륨 중 최댓값을 출력하라했는데, 그걸 놓쳐서 산으로 갔다온 문제
거기에 덤으로 dp배열 인덱스 순서를 바꿔쓰는 실수까지했다.


아이디어
- 모든 볼륨에대해서 연주 가능여부를 계산하고
- 노래를 순서대로 확인해서, 매단계마다 모든 크기의 볼륨에대해서 검사
- 그 후 마지막 단계에서 가장 큰 볼륨 찾아서 출력.
'''


#include <stdio.h>

using namespace std;
int main(){
    int n,s,m; 
    int array[101] = {0,};
    int dp[101][1001] = {0,};
    int result = -1;
    scanf("%d %d %d",&n,&s,&m);
    dp[0][s] = 1;
    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 0;j<m+1;j++){
            if (dp[i-1][j]==0)continue;
            if (j - array[i-1] >=0) dp[i][j-array[i-1]] = 1;
            if (j + array[i-1] <= m) dp[i][j+array[i-1]] = 1;
        }
    }
    for(int i = m;i>-1;i--){
        if(dp[n][i] == 1){
            result = i;
            break;
        }
    }
    printf("%d",result);

    return 0;
}
