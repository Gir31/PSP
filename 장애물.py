import sys
from collections import deque

def dijkstra():
    global graph, V, previous
    D = [sys.maxsize]
    D[0] = 0

    distance = 0
    queue = deque([(0, distance)])
    while queue:
        (current_vertex, distance) = queue.popleft()
        for adjacent, weight in graph[current_vertex].items():
            if distance + weight < D[adjacent]:
                D[adjacent] = distance + weight
                queue.append((adjacent, distance + weight))
                previous[adjacent] = current_vertex
    return D[V-1]

V, E = map(eval, input().split())

graph = {}
for i in range(V):
    graph[i] = {}
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u - 1][v - 1] = w
    graph[v - 1][u - 1] = w

previous = [-1]*V
original = dijkstra()
path = []
curr = V - 1
while curr != -1:
    path.insert(0, curr)
    curr = previous[curr]

most_double = original
for i in range(len(path) - 1):
    u, v = path[i], path[i + 1]
    graph[u][v] *= 2
    graph[v][u] *= 2
    most_double = max(most_double, dijkstra())
    graph[u][v] /= 2
    graph[v][u] /= 2

print(int(most_double - original))