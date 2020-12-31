'''
    맨처음에는 무조건 좌측 상단부터 탐색하면서 BFS를 수행했다.
    그 결과 문제 규칙에 위배되는 상단에 있는 물고기부터 먹고 그 다음 왼쪽에 있는 것을 처리한다는 규칙에 위배됐다.
    아래와 같은 경우에서 [0,5]를 방문한 후에 [1,1]을 가야하는데 [1,1]을 먼저 방문하는 경우가 발생했다. 
    0 0 9 0 1 0
    0 1 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    그래서 단순하게 찾는 것이 아니라 일단 경로의 길이가 같은 위치에 있는 물고기들을 모조리 구한 후에
    그 중에서 가장 왼쪽 상단에 있는 것을 고르는 방식을 택했다.
    그 결과
    6
    5 4 3 2 3 4
    4 3 2 3 4 5
    3 2 9 5 6 6
    2 1 2 3 4 5
    3 2 1 6 5 4
    6 6 6 6 6 6
    테스트 케이스에서 56이 나오던 결과가 60 이 나오면서 통과했다.
'''
from collections import deque

def bfs(n, shark_size):
    global shark_pos,aqua
    dx = [-1,0,0,1]
    dy = [0,-1,1,0]
    dq = deque()
    visited = [[0]*n for _ in range(n)]
    fish_map = [[0]*n for _ in range(n)]
    fish_dist = 0
    dq.append(shark_pos)
    visited[shark_pos[0]][shark_pos[1]] = 1

    while dq:
        node = dq.popleft()
        x = node[0]
        y = node[1]
        
        if fish_map[x][y] == 0 and 0<aqua[x][y]<shark_size:
            if fish_dist == 0:
                fish_dist = visited[x][y]
                fish_map[x][y] = fish_dist
            elif visited[x][y] == fish_dist:
                fish_map[x][y] = fish_dist
        
        for i in range(4):
            move_x = x + dx[i]
            move_y = y + dy[i]
            
            if 0<=move_x<n and 0<=move_y<n:
                if aqua[move_x][move_y]<=shark_size and visited[move_x][move_y]==0:
                    dq.append([move_x,move_y])
                    visited[move_x][move_y] = visited[x][y] + 1
                    
    
    for i in range(n):
        for j in range(n):
            if fish_map[i][j] != 0:
                shark_pos = [i,j]
                aqua[i][j] = 0
                return fish_map[i][j] -1
    
    return 0




n = int(input())
aqua = [list(map(int,input().split())) for _ in range(n)]

shark_size = 2
shark_pos = [0,0]
for i in range(n):
    for j in range(n):
        if aqua[i][j] == 9:
            shark_pos = [i,j]
            aqua[i][j] = 0
            break

temp_time = 1
real_time = 0
eatCount = 0

while temp_time != 0:
    temp_time = bfs(n,shark_size)
    if temp_time != 0:
        real_time += temp_time
        eatCount += 1
        if eatCount == shark_size:
            shark_size += 1
            eatCount = 0
print(real_time)
