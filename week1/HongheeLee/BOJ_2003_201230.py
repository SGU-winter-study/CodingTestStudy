'''
문제 설명 
  BOJ_2003 수들의 합 2
  자연수로 이루어진 수열의 i번째 항부터 j번째 항까지의 부분합이 특정값과 일치하는 경우의 수를 구하는 문제이다.
해결 전략
  투포인터를 활용한다. 
  부분합이 특정값보다 작으면 a[rt]를 추가하고 rt는 한칸 오른쪽으로 옮긴다.
  부분합이 특정값과 같으면 카운트를 세고 a[lt]를 빼주고 lt를 한칸 오른쪽으로 옮긴다.
  부분합이 특정값보다 크면 a[lt]를 빼주고 lt를 한칸 오른쪽으로 옮긴다.
  무한루프 종료조건은 부분합이 특정값보다 작은데 rt가 마지막항을 넘어간 경우. 즉, rt를 증가시켜야하는데 더이상 증가시킬 수 없는 경우.
'''
n, m = map(int, input().split())
a = list(map(int, input().split()))
rt = 1
lt = 0
tot = a[0]
cnt = 0 
while True:
    if tot < m:
        if rt < n:
            tot += a[rt]
            rt += 1
        else:
            break
    elif tot == m:
        cnt += 1
        tot -= a[lt]
        lt += 1
    else:
        tot -= a[lt]
        lt += 1
print(cnt)
