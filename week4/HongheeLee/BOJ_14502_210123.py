'''
    문제설명
        백준 14502 연구소(BFS 이용)
        벽 3개 세워서 바이러스로부터의 안전영역 최댓값 구하기
    해결전략
        바이러스도 없고 기존에 벽도 없는 빈칸에 벽 3개를 세워야한다. 
        itertools 모듈의 combinations 함수를 이용해 빈칸의 좌표 중에 3개를 선택하는 조합을 만든다.
        선택된 3개의 좌표에 벽을 세우고 주어진 2차원 리스트를 깊은 복사해서 매번 새롭게 바이러스가 퍼지는 결과를 검증한다.
        바이러스가 있는 좌표에서 상하좌우의 좌표가 범위 안에 속하고 빈칸일 때 바이러스가 퍼지도록 BFS를 이용해 구현한다.
        BFS을 마치고 나면 2차원 리스트에서 행단위로 0의 개수를 세서 기존 안전 영역의 최댓값과 비교해서 더 크면 갱신한다.
'''
import sys
from collections import deque
from itertools import combinations
import copy
input = sys.stdin.readline
def BFS(arr):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    Q = deque()
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 2:
                Q.append((i, j))
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if 0<= xx < n and 0 <= yy < m and arr[xx][yy]== 0:
                Q.append((xx, yy))
                arr[xx][yy] = 2
    return arr
n, m = map(int, input().split())
arr = []
INF = sys.maxsize
for _ in range(n):
    arr.append(list(map(int, input().split())))
sub = []
maxx = -2147000000
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            sub.append((i, j))
for a, b, c in list(combinations(sub, 3)):
    tmp_arr = copy.deepcopy(arr)
    tmp_arr[a[0]][a[1]] = 1
    tmp_arr[b[0]][b[1]] = 1
    tmp_arr[c[0]][c[1]] = 1
    tmp_dis = BFS(tmp_arr)
    res = 0
    for x in tmp_dis:
        res += x.count(0)
    maxx = max(res, maxx)
print(maxx)    
