'''
문제소개
    백준 1978 소수 찾기
    주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램
해결전략 
    1. 입력을 각각 int와 list로 받는다.
    2. list를 순회하며 소수인지 검증하고 맞으면 개수를 1 더한다.
    3. 소수 검증 함수: 1이면 소수X, 2이상일 때 2부터 자기자신-1까지 순회하며 나머지가 0이 되는 수가 있으면 소수X, 
       순회를 마쳤는데도 함수가 종료되지 않았으면 소수O
    4. 리스트 내부 원소를 모두 체크한 후 정답 출력
'''
def isPrime(x):
    if x == 1:
        return False
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    if isPrime(a[i]):
        cnt += 1
print(cnt)
