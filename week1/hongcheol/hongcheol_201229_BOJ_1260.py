#python으로도 해결하고 JAVA로도 풀이할 예정


def dfs(graph, start_node):
    visited, need_visit = list(), list()
    need_visit.append(start_node)

    while need_visit:
        node = need_visit.pop()
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])
    return visited
 
def bfs(graph, start_node):
    visited = list()
    need_visit = list()

    need_visit.append(start_node)

    while need_visit:
        node = need_visit.pop(0)
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])

    return visited

n,m,v = map(int,input().split())
G = dict()
for i in range(n):
    G[i+1] = []
for _ in range(m):
    n1, v1 = map(int,input().split())
    G[v1].append(n1)
    G[n1].append(v1)
for i in range(n):
    G[i+1].sort(reverse = True)
    
print(" ".join(map(str,dfs(G,v))))
for i in range(n):
    G[i+1].sort()
print(" ".join(map(str,bfs(G,v))))
