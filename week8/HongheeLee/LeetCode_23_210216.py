'''
    문제설명
        리트코드 23 k개 정렬 리스트 병합
    해결전략
        우선순위 큐를 이용한 리스트 병합. 우선순위 큐를 이용할 때는 heapq 모듈을 사용한다. 
        먼저 각 연결 리스트의 루트를 힙에 저장한다. 최소힙이므로 하나씩 꺼내어 병합하면 정렬 리스트를 얻을 수 있다.
        힙 추출 이후 다음 노드는 다시 저장한다.
'''
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        root = result = ListNode(None)
        heap = []
        
        # 각 연결 리스트의 루트를 힙에 저장
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
                
        # 힙 추출 이후 다음 노드는 다시 저장
        while heap:
            node = heapq.heappop(heap)
            idx = node[1]
            result.next = node[2]
            
            result = result.next
            if result.next:
                heapq.heappush(heap, (result.next.val, idx, result.next))
                
        return root.next
        

