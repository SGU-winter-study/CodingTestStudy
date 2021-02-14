'''
    문제설명
        리트코드 622 원형 큐 디자인
    해결전략
        원형 큐를 배열을 이용해서 디자인한다. 
        기존의 큐는 공간이 꽉 차게 되면 더 이상 요소를 추가할 수 없었다. 
        앞쪽에 요소들이 deQueue()되어서 공간이 생겨도 그쪽으로는 추가할 수 없는 방법이 없다. 
        그래서 앞쪽에 공간이 남아있다면 동그랗게 연결해 앞쪽 공간도 활용할 수 있는 방식이 원형큐이다.
        enQueue() : rear 포인터 위치에 값을 넣고 rear 포인터를 한 칸 앞으로 이동한다. 전체 길이만큼 모듈러 연산을 해서 포인터의 위치가 길이를 벗어나지 않게 한다.
        rear 포인터 위치가 None이 아니라면 공간이 꽉찬 상태이거나 비정상적인 경우이므로 False를 리턴한다.
        deQueue() : front 포인터 위치에 None을 넣어 삭제하고 front 포인터를 한 칸 앞으로 이동한다. 전체 길이만큼 모듈러 연산을 해서 포인터의 위치가 최대 길이를 넘지 않도록 한다.
        추가적으로 Front(), Rear(), isEmpty(), isFull() 함수도 구현하였다.  
'''
class MyCircularQueue(object):

    def __init__(self, k):
        self.q = [None] * k
        self.maxlen = k
        self.p1 = 0
        self.p2 = 0

    def enQueue(self, value):
        if self.q[self.p2] is None:
            self.q[self.p2] = value
            self.p2 = (self.p2 + 1) % self.maxlen
            return True
        else:
            return False
        
    def deQueue(self):
        if self.q[self.p1] is None:
            return False
        else:
            self.q[self.p1] = None
            self.p1 = (self.p1 + 1) % self.maxlen
            return True
        
    def Front(self):
        return -1 if self.q[self.p1] is None else self.q[self.p1]
        
    def Rear(self):
        return -1 if self.q[self.p2 - 1] is None else self.q[self.p2 - 1]

    def isEmpty(self):
        return self.p1 == self.p2 and self.q[self.p1] is None
        
    def isFull(self):
        return self.p1 == self.p2 and self.q[self.p1] is not None
