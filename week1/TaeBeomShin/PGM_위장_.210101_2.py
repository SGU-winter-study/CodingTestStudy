
'''
프로그래머스 Hash 연습
https://programmers.co.kr/learn/courses/30/lessons/42578 위장 문제
딕셔너리(해쉬) + 간단한 경우의수 찾기 응용

서로 다른 n개중 1개를 고르는 경우를 m번 반복.
선택하지 않는 경우의 수가 포함되나, 아무것도 선택하지 않으면 안되는 걸 고려하면 쉽게 품.
'''


def solution(clothes):
    answer, dict = 1, {}
    for cloth in clothes:
        if cloth[1] in dict:
            dict[cloth[1]] += 1
        else:
            dict[cloth[1]] = 1

    for k in dict.values():
        answer *= (k + 1)

    return answer - 1