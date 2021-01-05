'''
    문제설명
        백준 1966 프린터큐(큐 이용)
        큐 가장 앞에 있는 문서의 중요도를 확인하고 나머지 문서 중 중요도가 더 높은 문서가 있다면 이 문서를 인쇄하지 않고 가장 뒤에 재배치
        그렇지 않다면 인쇄. 
        어떤 문서가 몇 번째로 인쇄되는지 구한다.
    해결전략
        파이썬에서는 큐 자료구조를 이용할 때 deque를 사용한다. popleft와 appendleft를 사용할 수 있다.
        1. 문서의 개수와 인쇄 순서를 구하고 싶은 문서를 입력받는다.
        2. 문서의 순서와 중요도를 튜플 형태로 리스트에 각각 추가하고 이를 deque로 변환한다.
        3. deque의 맨 앞에서 하나를 pop하고 중요도가 더 높은 나머지 문서가 있으면 deque 가장 뒤에 다시 추가한다.
        4. 없으면 횟수를 하나 증가시키고 만약 이 문서가 인쇄 순서를 구하고자 하는 문서이면 인쇄 순서를 출력하고 루프를 종료한다.

'''
from collections import deque
a = int(input())
for i in range(a):
    n, m = map(int, input().split())
    res = [(pos, val) for pos, val in enumerate(list(map(int, input().split())))]
    cnt = 0
    res = deque(res)
    while True:
        tmp = res.popleft()
        if any(tmp[1] < x[1] for x in res):
            res.append(tmp)
        else:
            cnt += 1
            if m == tmp[0]:
                print(cnt)
                break
