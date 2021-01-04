'''
https://www.acmicpc.net/problem/1715
간단하게 heap을 이용해서 계산을 해주는 문제였다.

처음에 카드를 합친 후에 다음 카드 뭉치와 비교하는 로직에서 변수 저장 실수를 해서 오답이 나왔었다.
사소한 부분에서 실수가 많이 나오는데, 노트에 잘 쓰면서 수도코드정도까지는 만들어놓고 짜는 습관을 들여야겠다.
'''

import heapq,sys

n = int(sys.stdin.readline())
heap = []

for _ in range(n):
    data = int(sys.stdin.readline())
    heapq.heappush(heap,data)

ans = 0

while len(heap) != 1:
    o = heapq.heappop(heap)
    t = heapq.heappop(heap)
    v = o + t
    ans += v
    heapq.heappush(heap,v)

print(ans)
