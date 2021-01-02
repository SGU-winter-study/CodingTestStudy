'''
프로그래머스 Hash 연습
https://programmers.co.kr/learn/courses/30/lessons/42577 전화번호 목록 문제

이중 포문을 돌면서 string 내장함수인 startswith으로 접두사인지 확인해서 맞다면 False를 반환하고 종료.
아니라면 자동적으로 True 반환
'''
import string

def solution(phone_book):
    answer = True
    for i in range(len(phone_book)):
        a=phone_book[i]
        for j in range(len(phone_book)):
            b=phone_book[j]
            if i!=j and b.startswith(a)==True:
                answer=False
                break
        if(answer==False):
            break
    return answer