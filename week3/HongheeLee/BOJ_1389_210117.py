'''
    문제설명
        백준 1389 케빈 베이컨의 6단계 법칙(플로이드 알고리즘 이용)
        유저 수와 친구관계가 주어질 때 케빈 베이컨의 수가 가장 작은 사람을 구한다.
    해결전략
        문제 설명은 길지만 결국 모든 정점쌍에 대해 최단거리를 구하고 다른 정점으로 가는 최단거리의 합이 가장 작은 정점을 찾는 문제이다.
        거리를 나타내는 2차원 리스트를 최대 거리로 처음에 초기화한다.
        자기 자신으로 가는 거리는 0 이기 때문에 dis[i][i] = 0으로 초기화한다.
        입력으로 주어진 친구관계를 dis 리스트에 반영한다.
        i에서 j로 가는 최단거리를 구하는데 k 정점을 거쳐서 가는 것이 나은지 기존 방법이 나은지 검증하는 방식으로 
        3중 for문을 k, i, j 순으로 돌면서 검증한다.
        그 결과로 모든 정점쌍에 대한 최단거리를 dis 리스트에 구하게 되고 행마다 돌면서 최단거리의 합을 구한다.
        최단거리의 합이 가장 작은 정점을 찾는다.
'''
n, m = map(int, input().split())
dis = [[100] * (n+1) for _ in range(n+1)]
for i in range(1, n+1):
    dis[i][i] = 0
for _ in range(m):
    a, b = map(int, input().split())
    dis[a][b] = dis[b][a] = 1
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
res = [100]
for i in range(1, n+1):
    tot = 0
    for j in range(1, n+1):
        tot += dis[i][j]
    res.append(tot)
print(res.index(min(res)))
