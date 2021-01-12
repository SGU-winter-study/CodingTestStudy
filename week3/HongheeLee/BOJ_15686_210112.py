'''
    문제설명
        백준 15686 치킨배달(DFS 이용)
        n*n 도시에서 치킨집 m개를 고르고 나머지는 폐업시킬 때 도시의 치킨 거리의 최솟값을 구한다.
    해결전략
        이 문제는 결국 조합을 구하는 것이 중요하다.
        도시의 치킨집에서 m개를 뽑을 수 있는 조합을 DFS를 통해 구한다.
        DFS는 L(조합의 요소 개수)가 m이 되면 종료하고 그렇지 않으면 가지를 뻗는다
        조합은 중복을 허용하지 않고 순서만 다른 경우도 같은 것으로 간주하므로 DFS의 두번째 인자로 i+1을 넘겨 지금 선택한 원소 다음 인덱스부터 범위로 삼도록 한다. 
        조합을 완성하면 각 집의 좌표로부터 조합 내의 치킨집까지의 거리를 모두 계산해서 최솟값을 구하고 그 거리의 합을 해당 조합의 치킨 거리로 삼는다.
        치킨 거리가 기존 최솟값보다 작으면 교체한다. 
        이를 위해서 처음에 도시 정보를 2차원 리스트에 입력받고 이를 2중 for문으로 탐색하며 집의 좌표는 hs 리스트에 치킨집의 좌표는 ch 리스트에 넣는다.
'''
def DFS(L, s):
    global res
    if L == m:
        sum = 0
        for j in range(len(hs)):
            x1 = hs[j][0]
            y1 = hs[j][1]
            dis = 2147000000
            for x in cb:
                x2 = ck[x][0]
                y2 = ck[x][1]
                dis = min(dis, abs(x1-x2) + abs(y1-y2))
            sum += dis
        if sum < res:
            res = sum
    else:
        for i in range(s, len(ck)):
            cb[L] = i
            DFS(L+1, i+1)

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
hs = []
ck = []
cb = [0] * m
res = 2147000000
for i in range(n):
    for j in range(n):
        if board[i][j] == 1:
            hs.append((i, j))
        elif board[i][j] == 2:
            ck.append((i, j))
DFS(0, 0)
print(res)
