'''
처음에는 dp로 풀려고 접근했다가 동전이 무한하다는 조건을 보고서 그리디를 떠올렸다.
큰 애분터 낼 수 있는만큼 최대한 내고 남은 금액은 다음 금액 단위로 내는 방식으로 해결
'''

n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
cnt = 0
for i in range(n-1,-1,-1):
    cnt += k//coins[i]
    k %= coins[i]
print(cnt)
