'''
    문제설명
        리트코드 641 원형 데크 디자인
    해결전략
        이중 연결 리스트를 이용한 데크 구현
        add 메소드는 이미 있는 노드를 찢어내고 그 사이에 새로운 노드 new를 삽입하는 형태이다. 
        삽입 위치의 노드를 따로 저장하고, 삽입 위치 한칸 전의 노드가 새로운 노드를 가리키게 하고, 
        새로운 노드가 왼쪽은 한칸전 노드 오른쪽은 따로 저장한 삽입 위치의 노드를 가리키게 하고 마지막으로 따로 저장한 노드의 왼쪽이 새로운 노드를 가리키게 한다.
        이 add 메소드를 이용해 head 위치에 노드를 삽입하는 insertFront() 함수와 뒤쪽에 추가하는 insertLast() 함수를 구현한다.
        del 메소드를 이용해 deleteFront와 deleftLast 함수를 구현할 수 있다.
'''
class MyCircularDeque(object):

    def __init__(self, k):
        self.head, self.tail = ListNode(None), ListNode(None)
        self.k, self.len = k, 0
        self.head.right, self.tail.left = self.tail, self.head
        

    def _add(self, node, new):
        n = node.right
        node.right = new
        new.left, new.right = node, n
        n.left = new
        
    def _del(self, node):
        n = node.right.right
        node.right = n
        n.left = node
    
    
    def insertFront(self, value):
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.head, ListNode(value))
        return True
        

    def insertLast(self, value):
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.tail.left, ListNode(value))
        return True
        

    def deleteFront(self):
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.head)
        return True
        

    def deleteLast(self):
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.tail.left.left)
        return True
        

    def getFront(self):
        return self.head.right.val if self.len else -1
        

    def getRear(self):
        return self.tail.left.val if self.len else -1
        

    def isEmpty(self):
        return self.len == 0
        

    def isFull(self):
        return self.len == self.k
