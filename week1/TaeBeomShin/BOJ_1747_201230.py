'''
BOJ 1747
소수 + 팰린드롬 응용 간단한문제
1. 1000만 이하의 소수를 구한다. n이상 인 값만 소수리스트에 저장한다.
2. 저장한 수 목록을 순회하면서 펠린드롬인지 체크한다.(문자열로 바꾸어 비교한다.)
3. 답을 출력한다.

수학관련 문제나 문자열 응용 문제의 경우 c++보다 파이썬이 편한듯..
'''
n,M,sosu=int(input()),10000000,[]
check=[0,0]+[1]*M

for i in range(2,M):
    if check[i]:
        if(i>=n):sosu.append(i)
        for j in range(2*i,M,i):check[j]=False

for i in range(len(sosu)):
    num=str(sosu[i])
    if(num==num[::-1]):
        print(num)
        break