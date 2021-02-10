'''
    문제설명
        백준 4949 균형잡힌 세상 (스택 이용)
        유효한 괄호 찾기 문제와 유사하다.
    해결전략
        주어진 문자열에서 영문 알파벳과 공백을 무시한채 소괄호와 대괄호가 짝이 맞는지 체크한다.
        소괄호와 대괄호가 각각 짝이 맞는지 편하게 검사하기 위해서 dict을 활용한다.
        오른쪽 괄호가 나왔는데 스택이 비어있을 때, 오른쪽 괄호가 나왔는데 스택에서 꺼낸 괄호와 짝이 맞지 않을 때, 
        모든 문자열 검사를 마쳤는데 스택에 괄호가 남아있을 때 괄호가 균형맞춰져 있지 않다고 판단한다.
        모든 문자열 검사를 마치고나서 그 전까지 함수가 리턴되지 않았고, 스택에도 괄호가 남아있지 않다면 균형 맞춰져 있다고 판단한다.
'''
def is_valid(string):
    table = {
        ')' : '(',
        ']' : '['
    }
    stack = []
    for char in string:
        if char == '.':
            break
        if char.isalpha() or char == ' ':
            continue
        if char not in table:
            stack.append(char)
        elif not stack or table[char] != stack.pop():
            return False
    return len(stack) == 0

while True:
    string = input()
    if string == '.':
        break
    if is_valid(string):
        print('yes')
    else:
        print('no')
