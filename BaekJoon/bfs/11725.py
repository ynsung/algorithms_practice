# 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

# 첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
# 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

# -------- 입력-------- 
# 7
# 1 6
# 6 3
# 3 5
# 4 1
# 2 4
# 4 7
# -------- 출력-------- 
# 4
# 6
# 1
# 3
# 1
# 4

from collections import deque
import sys

n = int(sys.stdin.readline())
q, di, ans = deque(), {}, {}
visited = [False for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int,sys.stdin.readline().split())
    if a in di:
        di[a].append(b)
    else:
        di[a] = [b]
    if b in di:
        di[b].append(a)
    else:
        di[b] = [a]

q.append(1)
visited[1] = True
while q:
    x = q.popleft()
    for i in di[x]:
        if not visited[i]:
            q.append(i)
            visited[i] = True
            ans[i] = x
for i in range(2,n+1):
    print(ans[i])