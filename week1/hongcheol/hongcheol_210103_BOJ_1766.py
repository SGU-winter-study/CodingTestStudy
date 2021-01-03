'''
  
  https://www.acmicpc.net/problem/1766
  Heap과 위상정렬을 이용해서 구현하는 문제
  위상 정렬 부분이 까다로웠지만, 노트에 적어가면서 천천히 해결했다.
  
'''

import heapq

n, m = map(int,input().split())
ssen = [[] for _ in range(n+1)]
degree = [0]*(n+1)

heap = []
result = []

for _ in range(m):
    x, y = map(int,input().split())
    ssen[x].append(y)
    degree[y] += 1

for i in range(1,n+1):
    if degree[i] == 0:
        heapq.heappush(heap,i)
ans = []

while heap:
    data = heapq.heappop(heap)
    ans.append(data)

    for y in ssen[data]:
        degree[y] -= 1
        if degree[y] == 0:
            heapq.heappush(heap,y)
for answer in ans:
    print(answer, end = ' ')
