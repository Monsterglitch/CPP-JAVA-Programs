from collections import deque

def BFS(adj, start):
    visited = set()
    queue = deque()
    queue.append(start)
    while (queue):
        node = queue.popleft()
        if node not in visited:
            print(node)
            visited.add(node)
            for neighbour in adj[node]:
                if neighbour not in visited:
                    queue.append(neighbour)

visited = set()
def DFS(adj, start):
    if start not in visited:
        print(start)
        visited.add(start)
        for neighbour in adj[start]:
            DFS(adj, neighbour)
            
def iterative_DFS(adj, start):
    visited = set()
    stack = [start]
    while (stack):
        node = stack.pop()
        if node not in visited:
            print(node)
            visited.add(node)
            for neighbour in reversed(adj[node]):
                if neighbour not in visited:
                    stack.append(neighbour)

adj = [[1,2], [0,2,3], [0,4], [1,4], [2,3]]
BFS(adj, 0)
print()
DFS(adj, 0)
print()
iterative_DFS(adj, 0)