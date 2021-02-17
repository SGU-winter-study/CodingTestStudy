'''
    문제설명
        리트코드 706 해시맵 디자인
        put() : 키, 값을 해시맵에 삽입한다. 만약 이미 존재하는 키라면 업데이트한다.
        get() : 키에 해당하는 값을 조회한다. 만약 키가 존재하지 않는다면 -1 리턴.
        remove() : 키에 해당하는 키, 값을 해시맵에서 삭제
    해결전략
        해시 테이블을 구현하는 방식에는 개별 체이닝 방식과 오픈 어드레싱 방식이 있다.
        충돌이 발생한 경우 연결 리스트로 연결하는 방식이 개별 체이닝 방식. 오픈 어드레싱은 충돌 발생 시 탐사를 통해 빈 공간을 찾아나서는 방법.
        여기서는 개별 체이닝 방식으로 구현.
        모든 키는 정수형으로 지정하고 모듈로 연산을 한 나머지를 해시값으로 정했다.
'''

class MyHashMap(object):

    def __init__(self):
        self.size = 1000
        self.table = collections.defaultdict(ListNode)
        

    def put(self, key, value):
        index = key % self.size
        # 인덱스에 노드가 없다면 삽입 후 종료
        if self.table[index].value is None:
            self.table[index] = ListNode(key, value)
            return
        
        # 인덱스에 노드가 존재하는 경우 연결리스트 처리
        p = self.table[index]
        while p:
            if p.key == key:
                p.value = value
                return
            if p.next is None:
                break
            p = p.next
        p.next = ListNode(key, value)
            
    
    def get(self, key):
        index = key % self.size
        if self.table[index].value is None:
            return -1
        # 노드가 존재할 때 일치하는 키 탐색
        p = self.table[index]
        while p:
            if p.key == key:
                return p.value
            p = p.next
        return -1
        
    def remove(self, key):
        index = key % self.size
        if self.table[index].value is None:
            return
        
        # 인덱스의 첫 번째 노드일 때 삭제 처리
        p = self.table[index]
        if p.key == key:
            self.table[index] = ListNode() if p.next is None else p.next
            return
        
        # 연결 리스트 노드 삭제
        prev = p
        while p:
            if p.key == key:
                prev.next = p.next
                return
            prev, p = p, p.next

class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None
