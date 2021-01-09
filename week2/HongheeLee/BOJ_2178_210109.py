'''
    문제설명
        백준 2178 미로 탐색(BFS 이용)
        n X m 미로 (1,1) 위치에서 (n,m) 위치로 이동할 때 지나야 하는 최소 칸 수 구하기
    해결전략
        해당좌표의 이동 가능 여부가 표시되어있는 2차원 리스트 board,
        시작점으로부터 해당 좌표까지 가는데 지나는 최소 칸 수가 표시된 리스트 dis 사용. 여기선 시작 칸부터 1로 세기 때문에 1로 초기화.
        최단거리를 구할 때 사용하는 BFS는 큐를 이용해 구현한다. 현재 위치에서 이동 가능한 좌표를 12시, 3시, 6시, 9시 순으로 탐색하고 큐에 append한다.
        이후에 해당 좌표가 범위 내에 있고 board에서 볼 때 이동가능하면 pop하면서 해당 좌표로 이동한다.
        이미 방문한 좌표를 표시하기 위해 board에서 해당 좌표를 0으로 만든다. 
        최단 거리는 부모 노드까지의 최단거리 + 1이다.
'''
from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n, m = map(int, input().split())
board = [list(map(int, input()) for _ in range(n))]
dis = [[1]*m for _ in range(n)]
Q = deque()
Q.append((0,0))
board[0][0] = 0
while Q:
    tmp = Q.popleft()
    for i in range(4):
        x = tmp[0] + dx[i]
        y = tmp[0] + dy[i]
        if 0 <= x < n and 0 <= y < m and board[x][y] == 1:
            board[x][y] = 0
            Q.append((x, y))
            dis[x][y] = dis[tmp[0]][tmp[1]] + 1
print(dis[n-1][m-1])
