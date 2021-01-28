'''
    문제설명
        백준 10825 국영수(정렬 이용)
        국어(감소), 영어(증가), 수학(감소), 이름순(증가) 기준으로 정렬한다.
    해결전략
        이름과 국영수 과목 점수를 튜플 형태로 리스트에 추가한다.
        리스트를 정렬하는데 람다 함수를 이용해서 주어진 4가지 조건을 우선순위에 따라 적용해서 정렬한다. 
        정렬한 리스트에서 학생의 이름을 차례로 출력한다.
'''
import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    name, a, b, c = input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    arr.append((a, b, c, name))
arr.sort(key = lambda x : (-x[0], x[1], -x[2], x[3]))
for x in arr:
    print(x[3])
