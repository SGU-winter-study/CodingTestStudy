'''
    문제설명
        백준 1620 나는야 포켓몬 마스터 이다솜
        포켓몬 이름을 보면 번호를 말하고 번호를 보면 이름을 말하기
    해결전략
        포켓몬 번호와 이름이 입력으로 주어진다. 
        이름을 보고 번호를 찾는 것과 번호를 보고 이름을 찾는 것 모두 수행해야 한다.
        그 때문에 이름을 key로 번호를 value로 해서 dict에 추가하고, 번호를 key로 이름을 value로 해서 dict에 추가한다.
        이를 통해서 번호가 주어지면 그것을 dict의 키로 해서 이름을 value로 찾고 그 반대도 가능하도록 한다.
'''
import sys
input = sys.stdin.readline
n, m = map(int, input().strip().split())
pok = {}
for i in range(n):
    name = input().strip()
    pok[str(i+1)] = name
    pok[name] = str(i+1)
for _ in range(m):
    quest = input().strip()
    print(pok[quest])
