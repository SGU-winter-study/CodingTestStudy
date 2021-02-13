'''
    문제설명
        리트코드 232 스택을 이용한 큐 구현
    해결전략
        큐 마지막에 삽입하는 push, 큐 처음에 있는 요소를 제거하는 pop, 큐 처음에 있는 요소를 조회하는 peek, 큐가 비어있는지 여부를 리턴하는 empty를 구현한다.
        스택 연산만을 사용해서 풀기 위해서는 2개의 스택이 필요하다. 
'''
class MyQueue(object):

    def __init__(self):
        self.input = []
        self.output = []
        

    def push(self, x):
        self.input.append(x)
        

    def pop(self):
        self.peek()
        return self.output.pop()
        

    def peek(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        return self.output[-1]
        

    def empty(self):
        return self.input == [] and self.output == []
