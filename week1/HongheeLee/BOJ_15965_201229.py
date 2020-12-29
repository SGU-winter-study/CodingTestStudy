'''
문제 소개
    백준 15965 K번째 소수 찾기(에라토스테네스의 체 이용) 2960번과 유사
    N까지 소수의 개수 구하거나 K번째 소수 구할 때 해당 범위 자연수 하나하나 검증해서 구하면 시간초과 발생
해결 전략
    에라토스테네스의 체: 2부터 소수를 구하고자 하는 구간의 모든 수를 나열해 앞에서부터 차례대로 소수를 판단하고 해당 소수의 배수에는 표시한다.
    boolean형이 int형보다 메모리를 적게 사용하는데 개수가 많아질 때는 그 차이가 크리티컬해진다.   
'''
'''
소수 목록 산출하는 함수
def prime_list_eratos(n):
    ch = [True] * (n+1)
    for i in range(2, n+1):
        if ch[i] == True:
            for j in range(i+i, n+1, i):
                ch[j] = False
    return[i for i in range(2, n+1) if ch[i] == True]
'''
k = int(input())
n = 7500000
ch = [True] * n
cnt = 0
for i in range(2, n):
    if ch[i]:
        cnt += 1
        if cnt == k:
            print(i)
        for j in range(i, n, i):
            ch[j] = False