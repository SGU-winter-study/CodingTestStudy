'''
    문제설명
        백준 2468 안전영역 (DFS or BFS 이용)
        일정 높이 이하인 지역은 물에 잠기는데 물에 잠기지 않은 지점들이 상하좌우로 인접해 있을 때 안전한 영역이라고 한다.
        높이 정보가 있는 지도가 주어졌을 때 안전한 영역의 최대 개수를 계산.
    해결전략
        지도를 2차원 리스트로 입력받는다. 
        높이를 0~100까지 변화시키면서 안전 영역의 개수를 각각 구해서 최댓값을 찾는다.
        안전 영역 개수를 찾는 것은 2중 for문으로 지도 각 좌표를 탐색하며 BFS를 이용한다.
        물 높이보다 높고 아직 방문하지 않은 좌표를 만나면 안전한 영역을 하나 탐색한 것이므로 카운트하고
        해당 안전 영역에 포함되는 인근 지점들을 탐색한다. 
        큐에 넣고, 방문한 좌표를 체크 리스트에 표시하고, 12 3 6 9시 방향 탐색한다.
        해당 좌표가 범위 안에 있고 물 높이보다 높으며 체크리스트에서 방문 표시가 없을 때 그 좌표를 안전영역에 포함시키고 위의 과정을 반복한다. 
        이 문제에서 실수할 만한 포인트는 체크 리스트를 높이가 바뀔 때마다 0으로 초기화 해주어야 한다는 점이다!

    이 문제와 같이 플러드필 알고리즘, 즉 격자를 탐색하는 문제, 주어진 시작점에서 연결된 영역을 찾아내는 문제에서는 사실 DFS를 쓰나 BFS를 쓰나 상관없다.
    비슷한 로직을 활용해 DFS로도 아래와 같이 해결할 수 있다.
    (최단 경로를 찾을 때는 BFS, 경로의 개수를 찾을 때는 DFS를 사용한다.)
'''
#BFS 활용
from collections import deque
def BFS(a, b):
    Q = deque()
    Q.append((a, b))
    ch[a][b] = 1
    while Q:
        tmp = Q.popleft()
        for m in range(4):
            x = tmp[0] + dx[m]
            y = tmp[1] + dy[m]
            if 0 <= x < n and 0 <= y < n and board[x][y] > i and ch[x][y] == 0:
                Q.append((x, y))
                ch[x][y] = 1
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
cnt = 0
res = 0
for i in range(100):
    cnt = 0
    ch = [[0] * n for _ in range(n)]
    for j in range(n):
        for k in range(n):
            if board[j][k] > i and ch[j][k] == 0:
                cnt += 1
                BFS(j, k)
    res = max(res, cnt)
    if cnt == 0:
        break
print(res)

#DFS 활용
import sys
sys.setrecursionlimit(10**6)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
def DFS(a, b, h):
    ch[a][b] = 1
    for i in range(4):
        x = a + dx[i]
        y = b + dy[i]
        if 0 <= x < n and 0 <= y < n and board[x][y] > h and ch[x][y] == 0:
            DFS(x, y, h)
if __name__ == "__main__":
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    res = 0
    cnt = 0
    for h in range(100):
        ch = [[0]* n for _ in range(n)]
        cnt = 0
        for i in range(n):
            for j in range(n):
                if ch[i][j] == 0 and board[i][j] > h:
                    cnt += 1
                    DFS(i, j, h)       
        res = max(res, cnt)
        if cnt == 0:
            break
    print(res)
