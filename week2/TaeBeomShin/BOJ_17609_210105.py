'''
문자열 + 투포인터

1. 펠린드롬인지 확인 : 문자열 슬라이싱 통해 비교.
2. 세미펠린드롬인지 확인
    - 문자열 젤 처음과 젤 끝에 left,right변수 두고 같은 문자인지 확인한다.
    - 문자가 틀린걸 1번만 허용한다 -> 왼쪽에서 허용할 경우와 오른쪽에서 허용하는 경우를 나누어 생각한다.
    - 2번이상 다르면 세미펠린드롬이 아님.
3. 결과를 출력한다.

문자열에 투포인터 개념을 적용한다는게 쉽지않았다. 투포인터를 좀 더 공부해야할 듯.
'''
import sys;input=sys.stdin.readline
t=int(input())
def semipelindrom(word):
    front,back=True,True
    check=False
    left,right=0,len(word)-1
    while(left<=right):
        if(word[left]!=word[right]):
            if not check:
                check=True
                right-=1
            else:
                back=False
                break
        else:
            left+=1;right-=1

    check = False
    left, right = 0, len(word) - 1
    while(left<=right):
        if (word[left] != word[right]):
            if not check:
                check = True
                left += 1
            else:
                front = False
                break
        else:
            left += 1;right -= 1

    return front or back

for _ in range(t):
    word,c=input().strip(),2
    if(word==word[::-1]):
        c=0
    elif(semipelindrom(word)):c=1
    print(c)