'''
    문제설명
        백준 1935 후위 표기식 계산(스택 이용)
        후위 표기식의 피연산자는 A-Z로 주어지고 여기에 대응하는 추가적인 input이 정수로 주어진다.
    해결전략
        1. 피연산자의 값으로 주어진 input을 tmp 리스트에 담고 식에서 나타난 피연산자는 A-Z(65-90)므로 아스키코드로 tmp의 인덱스와 대응시킨다.
        2. 후위 표기식에서 피연산자를 만나면(여기서는 알파벳) 스택에 push한다.
        3. 후위 표기식에서 연산자를 만나면 스택에서 2번 pop해서 먼저 꺼낸 걸 두번째 피연산자, 나중에 꺼낸 걸 첫번째 피연산자로 삼아 연산하고 스택에 다시 push한다.
        4. 후위 표기식을 다 읽고 연산을 마치면 스택에 결과값 1개만 남아 있으므로 그것을 결과값으로 읽는다. 
'''
n = int(input())
a = input()
tmp = []
stack = []
for i in range(n):
    tmp.append(int(input()))
for x in a:
    if x.isalpha():
        stack.append(tmp[ord(x)-65])
    else:
        op2 = stack.pop()
        op1 = stack.pop()
        if x == '+':
            stack.append(op1 + op2)
        elif x == '-':
            stack.append(op1 - op2)
        elif x == '*':
            stack.append(op1 * op2)
        elif x == '/':
            stack.append(round(op1 / op2, 2))
print("%.2f" %stack[0])
