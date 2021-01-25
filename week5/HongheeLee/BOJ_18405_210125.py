'''
    문제설명
        백준 18405 경쟁적 전염(BFS 이용)
        시험관에서 바이러스가 퍼지는데 S초 후에 (x,y) 좌표에 있는 바이러스의 종류 구하기
    해결전략
        BFS(너비우선탐색)을 이용한다. 
        초기 시험관의 상태를 2차원 리스트에 담는다.
        초기 시험관에서 0이 아닌 좌표를 찾아 리스트에 (바이러스 번호, x좌표, y좌표, 초) 형태로 넣는다.
        작은 번호의 바이러스부터 퍼지기 시작하므로 정렬한다. 시작할 때 한번만 정렬하면 앞으로 계속 정렬된 상태로 바이러스는 퍼진다.
        또한 효율적인 pop연산을 위해 deque형을 사용했다. 
        이제 큐에 있는 원소들을 하나씩 빼서 상하좌우 순서대로 좌표를 뻗어나가는데 x,y 좌표가 범위 안에 있고 다른 바이러스가 퍼지지 않은 곳에 대해서
        바이러스가 퍼졌음을 표시하고 큐에다가 정해진 형태로 넣어준다.
        큐에서 뺀 원소의 초가 문제에서 주어진 초와 같아지면 바이러스 확산이 완료된 것이므로 BFS 함수를 종료하고 그때 원하는 좌표의 바이러스 정보를 구한다.
'''
import sys
from collections import deque
input = sys.stdin.readline

def BFS():
    Q = []
    for i in range(n):
        for j in range(n):
            if dis[i][j] != 0:
                Q.append((dis[i][j], i, j, 0))
    Q.sort()
    Q = deque(Q)
    while Q:
        num, x, y, cnt = Q.popleft()
        if cnt == s:
            return
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if 0 <= xx < n and 0 <= yy < n and dis[xx][yy] == 0:
                dis[xx][yy] = num
                Q.append((num, xx, yy, cnt+1))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, k = map(int, input().split())
dis = []
for i in range(n):
    dis.append(list(map(int, input().split())))
s, x, y = map(int, input().split())
BFS()
print(dis[x-1][y-1])
