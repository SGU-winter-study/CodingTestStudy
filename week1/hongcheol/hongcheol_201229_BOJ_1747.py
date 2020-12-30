'''
boj 1747
소수 + 펠린드롬 문제
다음 두 가지 방식으로 고민
1. 펠린드롬을 만들어서 소수인지 확인하기
2. 소수인지 판별 후 펠린드롬인지 확인하기

시간은 1번이 더 빠르겠지만 실전에서 만났을 때, 처음에는 2번으로 할 가능성이 커서 2번으로 구현
isPalindrome(n)에서 str()로 형변환 하는 것보다 간단하게 나누기 연산을 하는게 시간이 100ms 정도 더 빨랐다

사용 메모리를 줄여보려고 에라토스테네스의 체를 사용하지않았는데 마침 태범님이 오늘 새벽에 같은 문제를 에라토스테네스의 체를 이용해서
풀이를 하셔서 결과를 비교해봤는데 속도차이가 컸다.
맨처음에 푼 풀이는 아래에 첨부한다
'''

#최종 제출 풀이
def isPalindrome(n):
    array = []
    l = 0
    while n > 0:
        array.append(n%10)
        n //= 10
        l += 1
    for i in range(l//2+1):
        if array[i] != array[l-1-i]:
            return False
    return True

n = int(input())
size = 2000000
num = [True]*(size)
prime = []
m = int(size**0.5)
for i in range(2,m+1):
    if num[i] == True:
        for j in range(i+i,size,i):
            num[j] = False
for i in range(2,2000000):
    if num[i] == True:
        prime.append(i)
for data in prime:
    if data >= n and isPalindrome(data) == True:
        print(data)
        break
   
#맨 처음 풀이 
def isPalindrome(n):
    array = []
    l = 0
    while n > 0:
        array.append(n%10)
        n //= 10
        l += 1
    for i in range(l//2+1):
        if array[i] != array[l-1-i]:
            return False
    return True

n = int(input())
if n == 1:
    print(2)
else:
    for i in range(n,2000000):
        isPrime = True
        for j in range(2,int(i**0.5)+1):
            if i%j == 0:
                isPrime = False
                break
        if isPrime:
            if isPalindrome(i):
                print(i)
                break
