'''
    문제설명 
        백준 14888 연산자 끼워넣기(브루드포스 알고리즘 이용)
        주어진 수열에 주어진 연산자를 끼워넣을 때 최댓값과 최솟값 구하기
    해결전략
        주어진 연산자의 순열을 구해야 한다. 연산자의 개수를 감소시키는 방식으로 순열을 구하는 방법과 파이썬 itertools 모듈을 이용하는 방법으로 풀 수 있다. 
        DFS로 순열 일일이 구하고 최댓값 최솟값 비교해 보았지만 그렇게 하면 같은 연산자인데도 다르게 취급해서 중복되는 순열이 많아져서 시간초과가 나온다.
        1. 따라서 같은 연산자끼리는 같게 취급해주기 위해 특정 연산자를 선택하면 연산자 개수를 감소시키고 바로 연산 결과를 갱신하는 방식으로 DFS를 구성할 수 있다.
        그렇게 하면 중복되는 순열이 사라져서 더 간단하게 최댓값 최솟값을 구할 수 있다. 
        2. 혹은 파이썬 모듈을 이용해서 전체 순열을 간단히 구하고 이를 set()을 이용해 중복을 제거한다음 결과를 비교할 수도 있다.
        이렇게 하면 연산자로 이루어진 순열을 먼저 완성한 뒤, 주어진 수열과 연산자 순열을 차례로 읽으며 연산자에 따른 연산을 수행해 식의 결과를 구한다.
        그 결과에 따라 최댓값, 최솟값을 갱신해 모든 순열을 탐색하고 나면 최댓값과 최솟값을 구할 수 있다.
'''
# 연산자 개수 감소시키며 DFS 이용하는 방법
import sys
input = sys.stdin.readline
def DFS(L, res, p, m, mul, div):
    global maxx
    global minn
    if L == n:
        maxx = max(res, maxx)
        minn = min(res, minn)
    else:
        if p:
            DFS(L+1, res+arr[L], p-1, m, mul, div)
        if m:
            DFS(L+1, res-arr[L], p, m-1, mul, div)
        if mul:
            DFS(L+1, res*arr[L], p, m, mul-1, div)
        if div:
            if res < 0:
                DFS(L+1, -(-res // arr[L]), p, m, mul, div-1)
            else:
                DFS(L+1, res//arr[L], p, m, mul, div-1)
n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))
maxx = -2147000000
minn = 2147000000
DFS(1, arr[0], op[0], op[1], op[2], op[3])
print(maxx)
print(minn)

# 파이썬 permutaions 이용하는 방법
import sys
from itertools import permutations
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
a,b,c,d = map(int, sys.stdin.readline().split())
oper = ['+'] * a + ['-'] * b + ['*'] * c + ['/'] * d
oper_set = []
for number in list(permutations(oper)):
    oper_set.append(number)
oper_set = list(set(oper_set))
maxx = -2147000000
minn = 2147000000
for case in oper_set:
    tot = arr[0]
    for i in range(n-1):
        if case[i] == '+':
            tot += arr[i+1]
        elif case[i] == '-':
            tot -= arr[i+1]
        elif case[i] == '*':
            tot *= arr[i+1]
        elif case[i] == '/':
            if tot < 0:
                tot = -(-tot // arr[i+1])
            else:
                tot //= arr[i+1]
    maxx = max(maxx, tot)
    minn = min(minn, tot)
print(maxx)
print(minn)
