'''
    문제설명
        프로그래머스 프린터
    해결전략
        덱를 이용해서 해결한다. 파이썬의 deque를 활용하면 맨 앞 요소를 뺄 때 시간복잡도를 줄일 수 있다.
        덱에 (문서 위치, 문서의 우선순위)의 튜플 형태로 주어진 정보를 넣는다.
        덱(프린터)에서 맨 앞에 있는 문서를 꺼내서 뒤에 그보다 더 큰 우선순위를 가진 문서가 없으면 출력한다 (ans를 1 더해준다.)
        그리고 출력한 문서의 처음 위치를 확인해서 확인하고자 하는 문서라면 이번이 몇번째 출력인지 확인해서 리턴한다.
        만약 더 큰 우선순위를 가진 문서가 있으면 append()를 통해 덱의 맨 뒤에 다시 추가해준다. 
'''
from collections import deque
def solution(priorities, location):
    ans = 0
    Q = deque()
    for idx, x in enumerate(priorities):
        Q.append((idx, x))
    
    while Q:
        tmp = Q.popleft()
        for x in Q:
            if tmp[1] < x[1]:
                Q.append(tmp)
                break
        else:
            ans += 1
            if tmp[0] == location:
                return ans
