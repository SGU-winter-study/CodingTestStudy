'''
    문제설명
        프로그래머스 기능개발
    해결전략
        덱을 이용해서 문제를 해결한다.
        기능의 개발 진도와 개발 속도가 주어진다. 이를 이용해 해당 기능이 개발되기까지 남은 일수를 계산해서 새로운 리스트로 만든다.
        그 리스트를 덱으로 변환한 뒤 앞에서부터 popleft()로 차례로 꺼낸다.
        그 뒤에 있는 기능들의 남은 일수가 지금 완료한 기능의 일수보다 작다면 차례로 하나씩 꺼내고 res 값을 하나씩 더해준다.
        아직 개발이 완료되지 않은 기능을 만나면 while문을 종료하고 결과 리스트에 몇 개의 기능을 이번에 구현했는지 추가한다.
        이를 모든 기능이 개발이 완료되어 덱이 빌 때까지 반복한다.
'''
from collections import deque
def solution(progresses, speeds):
    answer = []
    sub = [100 - x for x in progresses]
    for i in range(len(sub)):
        if sub[i] % speeds[i] == 0:
            sub[i] = sub[i] // speeds[i]
        else:
            sub[i] = sub[i] // speeds[i] + 1
    Q = deque(sub)
    
    while Q:
        res = 1
        tmp = Q.popleft()
        while Q:
            if tmp >= Q[0]:
                Q.popleft()
                res += 1
            else:
                break
        answer.append(res)
    
    return answer
