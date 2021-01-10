'''
    문제설명
        백준 2667 단지번호붙이기 (DFS 이용)
        지도에서 연결된 집의 모임인 단지수를 출력하고 각 단지에 속하는 집의 수를 오름차순으로 출력.
    해결전략
        지도를 2차원 리스트로 입력받고 2중 for문으로 모두 탐색한다.
        1을 만났을 때(집이 있는 곳) DFS를 호출한다. 
        집이 있으면 집의 수를 카운트하고 지도에서 0으로 바꿔서 다시 탐색되지 않게 한다.
        그 다음 12시, 3시, 6시, 9시 차례로 탐색하며 좌표가 범위 안에 있고 집이 있으면 이동하고 그 좌표를 기준으로 DFS를 호출한다.
        DFS가 모두 종료되면 해당 단지의 집의 수를 구할 수 있고 이를 결과 리스트에 추가한다.
        결과 리스트의 길이가 단지의 수이고 결과 리스트에는 각 단지에 속하는 집의 수가 담겨 있으므로 정렬해서 출력한다.
'''
def DFS(a, b):
    global cnt
    cnt += 1
    borad[a][b] = 0
    for i in range(4):
        x = a + dx[i]
        y = b + dy[i]
        if 0<=x<n and 0<=y<n and borad[x][y] == 1:
            DFS(x,y)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n = int(input())
borad = [list(map(int, input())) for _ in range(n)]
res = []
for i in range(n):
    for j in range(n):
        if borad[i][j] == 1:
            cnt = 0
            DFS(i, j)
            res.append(cnt)
res.sort()
print(len(res))
for x in res:
    print(x)
