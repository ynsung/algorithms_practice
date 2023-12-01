# n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다. 당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다.
# 이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.

# 송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다.
# 전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때,
# 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.


# n은 2 이상 100 이하인 자연수입니다.
# wires는 길이가 n-1인 정수형 2차원 배열입니다.
# wires의 각 원소는 [v1, v2] 2개의 자연수로 이루어져 있으며, 이는 전력망의 v1번 송전탑과 v2번 송전탑이 전선으로 연결되어 있다는 것을 의미합니다.
# 1 ≤ v1 < v2 ≤ n 입니다.
# 전력망 네트워크가 하나의 트리 형태가 아닌 경우는 입력으로 주어지지 않습니다.

# n	  wires	                                              result
# 9	  [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]	  3
# 4	  [[1,2],[2,3],[3,4]]	                                0
# 7	  [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]	              1

from collections import deque

def make_graph(wires, n):
    graph = [[] for _ in range(n+1)]
    for i in range(len(wires)):
        graph[wires[i][0]].append(wires[i][1])
        graph[wires[i][1]].append(wires[i][0])
    return graph

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    list = []

    while queue:
        v = queue.popleft()
        list.append(v)
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    return list

def solution(n, wires):
    answer = 100
    
    # i번째 간선을 잘랐을 때
    for i in range(len(wires)):
        wire = wires[:i]+wires[i+1:]
        graph = make_graph(wire, n)

        # 탐색의 시작노드
        node = []
        node = set(node)
        for j in range(1, n+1):
            visited = [False] * (n+1)
            bfs(graph, j, visited)
            node.add(visited.count(True))

        if max(node)-min(node) < answer:
            answer = max(node)-min(node)
    return answer