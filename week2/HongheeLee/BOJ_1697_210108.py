'''
    문제설명
        백준 1697 숨바꼭질(BFS 이용)
        수빈이의 현재 위치에서 동생의 위치까지 갈 수 있는 최단시간 구하기
    해결전략
        BFS 이용한다. BFS는 레벨 탐색하는데 큐를 이용해서 구현할 수 있다.
        시작점에서 해당 좌표까지 걸리는 시간을 표시하는 dis 리스트와 이미 방문한 노드를 표시하는 ch 리스트를 활용한다.
        큐의 가장 앞에 있는 것부터 pop한다. (여기선 deque의 popleft)
        그 결과 나온 좌표가 목적지와 같으면 while문을 break하고 그렇지 않으면 그 좌표를 기준으로 이동한다. 여기서는 -1, +1, *2.
        이동한 좌표가 주어진 범위 0~100000에 있고 이전에 방문한 적이 없다면 큐에 append해서 탐색한 것으로 한다. 
        이 과정을 목적지에 도달할 때까지 반복한다. 
        dis 리스트에서 목적지의 좌표를 인덱스로 조회하면 도달하기까지의 최단시간을 구할 수 있다.
'''
from collections import deque
MAX = 100000
dis = [0] * (MAX+1)
ch = [0] * (MAX+1)
n, k = map(int, input().split())
dis[n] = 0
ch[n] = 1
dQ = deque()
dQ.append(n)
while dQ:
    now = dQ.popleft()
    if now == k:
        break
    for next in (now-1, now+1, 2*now):
        if 0 <= next <= MAX and ch[next] == 0:
            ch[next] = 1
            dis[next] = dis[now] + 1
            dQ.append(next)
print(dis[k])
