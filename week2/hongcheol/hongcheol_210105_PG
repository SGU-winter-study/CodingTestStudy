'''
코딩테스트 연습>깊이/너비 우선 탐색 > 네트워크 문제
DFS/BFS를 주로 반복문을 통해서 구현했었는데, 재귀함수를 이용해서 풀어봤다.


'''
visited = [False]*200
count = 0
def dfs(i,computers):
    global visited
    global count
    count += 1
    visited[i] = True
    for j in range(len(computers[i])):
        if computers[i][j] == 1 and not visited[j]:
            dfs(j,computers)
    
    
def solution(n, computers):
    answer = 0
    global visited
    for i in range(n):
        if visited[i] == False:
            dfs(i,computers)
            answer += 1
    return answer
