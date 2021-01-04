'''
    문제설명
        백준 1918 후위 표기식(스택 이용)
        input으로 주어진 중위 표기식을 후위표기식으로 변환한다. 
    해결전략
        1. 피연산자는 그대로 출력하고 연산자는 우선순위에 따라 스택에서 push, pop한다.
        2. '(' 연산자는 제일 우선순위 낮기 때문에 무조건 push한다.
        3. '*'와 '/' 연산자는 우선순위가 제일 높지만 우선순위가 같다면 왼쪽에 있는게 우선이기 때문에 스택에 먼저 들어있는 '*'나 '/'를 pop해서 출력하고 그 다음 push한다.
        4. '+'와 '-' 연산자는 '(' 연산자를 만나기 전까지 스택에 있는 연산자들을 모두 pop해서 출력하고 그 다음 push한다.
        5. ')'는 '('를 만날 때까지 pop해서 괄호 사이에 있는 연산자들을 출력해준다. 그리고 한번 더 pop해서 '('를 스택에서 제거한다.
        6. 중위 표기식을 다 읽고나서 스택에 남은 연산자들은 스택에서 위쪽에 위치한 것이 우선순위가 높으므로 차례로 pop해서 출력한다.
'''
a = input()
stack = []
res = ''
for x in a:
    if x.isalpha():
        res += x
    elif x == '(':
        stack.append(x)
    elif x == '*' or x == '/':
        while stack and (stack[-1] == '*' or stack[-1] == '/'):
            res += stack.pop()
        stack.append(x)
    elif x == '+' or x == '-':
        while stack and stack[-1] != '(':
            res += stack.pop()
        stack.append(x)
    elif x == ')':
        while stack and stack[-1] != '(':
            res += stack.pop()
        stack.pop()
while stack:
    res += stack.pop()
print(res)
