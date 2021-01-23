'''
https://www.acmicpc.net/problem/17298
스택으로 해결한 문제.
처음에는 오큰수를 찾은 다음에, 어떤 항목에대한 오큰수인지 저장하는 로직이 안 떠올랐다.
그래서 스택에 넣을 때, 값이랑 인덱스를 같이 넣어서 pop할 때, 꺼내서 해당 인덱스로 접근해서 해결했다.
그리고 다 푼 다음에, 출력형식 안 맞추고 디버깅하던 상태로 제출해서 한 번 틀렸었다.
'''

n = int(input())
num = list(map(int,input().split()))
stack = []
for i in range(n):
    if stack:
        if stack[-1][0] >= num[i]:
            stack.append([num[i],i])
        else:
            while stack and stack[-1][0] < num[i]:
                temp = stack.pop()
                num[temp[1]] = num[i]
            stack.append([num[i],i])
    else: stack.append([num[i],i])
if stack:
    while stack:
        temp = stack.pop()
        num[temp[1]] = -1
num[-1] = -1
for data in num:
    print(data,end= ' ')
