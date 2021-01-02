'''
    https://www.acmicpc.net/problem/15686
    처음에 BFS로 후보군을 추려내려고했다
    BFS를 한 결과를 보고서야 BFS를 하면 복잡해지기만하고 불필요한 연산이 많아질거라 생각
    -> 그래서 조합을 이용하기로 결정

    완탐 과정에서 min_dist랑 temp를 최댓값으로 설정했다. 근데 애매하게 2*n+1로 했더니 이상한 결과가 나왔었다.
    그래서 그냥 깔끔하게 100000으로 처리해서 제출했더니 정답이 나왔다.

    다 풀고서 생각해보니까 집의 위치를 찾으려고 불필요하게 반복문을 여러번 돌릴 필요가 없었다.
    그냥 입력 받을 때, 전처리로 집 위치 저장해주면 되는거였다.
    그 결과 시간까지 줄이면서 정답 완료

'''
import itertools
n, m = map(int,input().split())

chicken = []
homes = []
city = [list(map(int,input().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        if city[i][j] == 2:
            chicken.append([i,j])
        if city[i][j] == 1:
            homes.append([i,j])
combi = list(itertools.combinations(chicken,m))
min_dist = 100000
for i in range(len(combi)):
    dist = 0
    for home in homes:
        temp = 100000
        for j in range(m):
            temp = min(temp,abs(home[0]-combi[i][j][0])+ abs(home[1]-combi[i][j][1]))
        dist += temp
    min_dist = min(min_dist,dist)

print(min_dist)
