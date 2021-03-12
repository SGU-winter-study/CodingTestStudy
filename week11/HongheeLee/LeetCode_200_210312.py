'''
    문제설명
        리트코드 200 섬의 개수
        연결되어있는 1의 덩어리 개수를 구하라
    해결전략
        DFS로 그래프 탐색을 진행한다. 
        정확히 그래프의 형태는 아니지만 리스트의 원소 하나하나를 정점으로 간주하고 모든 정점이 동서남북으로 연결되어있는 그래프로 가정한다.
        모든 정점을 차례로 탐색하며 1을 만나면 그 점을 시작점으로 하여 DFS 탐색을 시작한다.
        방문한 정점을 표시하기 위해 따로 리스트를 만들지 않고 주어진 리스트의 값을 0으로 변경함으로써 방문한 정점을 표시해 일종의 가지치기를 한다.
        방문한 정점에서 12시, 3시, 6시, 9시 방향 순으로 탐색하고 그 점이 주어진 범위를 벗어나지 않고 리스트에서 "1" 표시되어 있으면 그 점을 기준으로 DFS 탐색을 이어간다.
        한번 DFS 탐색을 마치면 연결되어 있는 섬을 하나 탐색한 것이므로 섬의 개수를 1개 증가시킨다.
        dfs 함수를 클래스 내에 따로 만들면 함수를 호출할 때 self.를 붙이고 호출해야하고 grid 변수도 함수 호출시 전달해야한다.
        하지만 중첩함수의 형태로 구현한다면 내부에 있는 함수는 부모 함수의 변수를 자유롭게 호출할 수 있으므로 구현이 더 간단해진다.     
'''
class Solution(object):         
    def numIslands(self, grid):
        def dfs(x, y):
            dx = [-1, 0, 1, 0]
            dy = [0, 1, 0, -1]
            grid[x][y] = "0"
            for i in range(4):
                xx = x + dx[i]
                yy = y + dy[i]
                if 0 <= xx < len(grid) and 0 <= yy < len(grid[0]) and grid[xx][yy] == "1":
                    dfs(xx, yy)
            
        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    cnt += 1
                    dfs(i, j)
        return cnt

class Solution(object):         
    def dfs(self, x, y, grid):
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        grid[x][y] = "0"
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if 0 <= xx < len(grid) and 0 <= yy < len(grid[0]) and grid[xx][yy] == "1":
                self.dfs(xx, yy, grid)
                
    def numIslands(self, grid):
        if not grid:
            return 0
        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    cnt += 1
                    self.dfs(i, j, grid)
        return cnt
