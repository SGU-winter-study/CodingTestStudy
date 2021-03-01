'''
    문제설명
        PGM 모의고사 (완전탐색)
    해결전략
        1번, 2번, 3번 참가자의 패턴을 리스트 형태로 구성한다.
        주어진 정답과 하나하나 매치하며 각 참가자의 점수를 갱신한다.
        매치할 때 주어진 정답의 길이와 패턴의 길이가 다를 수 있으므로 나머지 연산자를 활용해서 패턴이 잘 반복되어 매치될 수 있게 한다.
'''
def solution(answers):
    answer = []
    a = [0, 0, 0]
    b = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]

    for i in range(len(b)):
        for j in range(len(answers)):
            if answers[j] == b[i][j % len(b[i])]:
                a[i] += 1

    for i in range(len(a)):
        if a[i] == max(a):
            answer.append(i+1)
    return answer
