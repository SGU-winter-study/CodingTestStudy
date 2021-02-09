from collections import deque
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 1. 연결리스트를 리스트로 변환해서 팰린드롬 판별. 첫번째 값 꺼내오는데 시프팅이 일어나기 때문에 시간복잡도 O(n).
class Solution(object):
    def isPalindrome(self, head):
        q = []

        if not head:
            return True
        
        node = head
        while node is not None:
            q.append(node.val)
            node = node.next
        
        while len(q) > 1:
            if q.pop(0) != q.pop():
                return False
        return True

# 2. 연결리스트를 덱으로 변환해서 팰린드롬 판별. 덱은 이중연결리스트의 형태로 구현되어 있기 때문에 양쪽 방향 모두 값을 꺼내오는데 시간 복잡도 O(1)
class Solution(object):
    def isPalindrome(self, head):
        q = deque()
        
        if not head:
            return True
        
        node = head
        while node is not None:
            q.append(node.val)
            node = node.next
        
        while len(q) > 1:
            if q.popleft() != q.pop():
                return False
        return True
'''
3. 연결리스트를 변환하지 않고 런너를 이용한 풀이. 
느린 런너는 한칸씩 빠른 런너는 두칸씩 이동하며 빠른 런너가 끝에 다다를 때 느린 런너는 정확히 중간지점에 도달
느린 런너가 중간까지 이동하면서 역순으로 연결 리스트 rev를 만들어 나간다. 중간에 도달한 느린 런너가 나머지 경로를 이동할 때
역순으로 만든 연결 리스트의 값들과 일치하는지 확인해나가면 된다.
빠른 런너와 느린 런너의 초기값은 head에서 시작하고 역순 연결리스트는 None에서 시작한다.
역순 연결리스트를 만드는 부분에서 다중할당이 핵심이다.
'''
class Solution(object):
    def isPalindrome(self, head):
        rev = None
        slow = fast = head

        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        
        while rev and rev.val == slow.val:
            slow, rev = slow.next, rev.next
        return not rev
