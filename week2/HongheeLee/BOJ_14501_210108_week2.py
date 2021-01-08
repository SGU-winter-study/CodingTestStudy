'''
    문제설명
        백준 14501 퇴사 (DFS 이용)
        주어진 기간동안 상담을 진행해서 최대로 얻을 수 있는 이익 구하기
    해결전략
        전체 집합에서 부분 집합을 만드는데 어떤 원소를 포함시킬지 안할지 하나하나 검사하는 것과 유사하다.
        DFS는 크게 if else 구조로 재귀함수 종료 조건과 그때 실행, 종료 전 어떻게 재귀함수 호출할지로 나누어 구현한다. 
        앞에서부터 차례차례 검사한다. 1일 상담 하는지 안하는지 둘다 해본다. L은 날짜, sum은 총 금액으로 한다.
            상담하면 그 금액 더해주고 그 시간만큼 지난 날짜에서 상담하는지 안하는지 또 판단. 해당 상담을 할 때 n+1일을 넘어가게 되면 상담 X
            상담 안한다면 금액 변화 없이 다음날로 넘어가 다시 상담 하는지 안하는지 판단. 
            날짜가 n+1일이 되면 재귀호출을 종료하고 총 금액을 지금까지의 최대 이익과 비교해서 더 크면 업데이트한다.       
'''
def DFS(L, sum):
    global largest
    if L == n+1:
        if sum > largest:
            largest = sum
    else:
        if L + lt[L] <= n+1:
            DFS(L + lt[L], sum + lp[L])
        DFS(L + 1, sum)
n = int(input())
lt = [0]
lp = [0]
for i in range(n):
    a, b = map(int, input().split())
    lt.append(a)
    lp.append(b)
largest = -247000000
DFS(1, 0)
print(largest)
