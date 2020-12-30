#https://programmers.co.kr/learn/courses/30/lessons/60058
'''
문제의 조건에 주어진 구현 조건에 맞춰서 단순하게 구현만 하면 되는 문제여서 주어진대로 구현
단순한 구현이기 때문에 풀어보신 후에 코드를 보시는 것을 추천드립니다.

1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
  4-3. ')'를 다시 붙입니다. 
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
  4-5. 생성된 문자열을 반환합니다.

'''
def change(w):
    if w == '':
        return ''
    
    u = ''
    v = ''
    split = 0
    left_count, right_count = 0,0
    for i in range(len(w)):
        if w[i] == '(':
            left_count += 1
            u += w[i]
        else:
            right_count += 1
            u += w[i]
        if left_count == right_count:
            v = w[i+1:]
            break
    if check(u):
        return u+change(v)
    else:
        temp = ''
        temp += '('
        temp += change(v)
        temp += ')'
        u = u[1:-1]
        for i in range(len(u)):
            if u[i] == '(':
                temp += ')'
            else:
                temp += '('
        return temp
    
#stack을 이용해서 (를 모으고 )이 나올때마다 (을 pop해서 균형이 잡혀있는지 확인한다. )이 남았는데 남아있는 (이 없으면 균형잡힌게 아니니까 false
#이거 잘 통과하면 s는 균형잡힌 괄호
def check(s):
    stack = []
    for data in s:
        if data == '(':
            stack.append(data)
        else:
            if stack != []:
                stack.pop()
            else:
                return False
    return True
    
def solution(p):
    answer = ''
    answer = change(p)
    
    return answer
