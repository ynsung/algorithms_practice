# N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
# N개의 자연수 중에서 M개를 고른 수열

# 첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
# 둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
# 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
# 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

# --------입력--------
# 3 1
# 4 4 2
# --------출력--------
# 2
# 4

import sys
sys.setrecursionlimit(10**6)

def dfs(idx, newli):
    newli = newli + [li[idx]]
    if len(newli) == m:
        ans_set.add(tuple(newli))  # 리스트를 튜플로 변환하여 Set에 추가
        return
    visited[idx] = True
    for i in range(n):
        if not visited[i]:
            dfs(i, newli)
    visited[idx] = False

n, m = map(int, sys.stdin.readline().split())
li = list(map(int, sys.stdin.readline().split()))
visited = [False for _ in range(n)]
ans_set = set()  # 중복된 요소를 방지하기 위한 Set
for i in range(n):
    dfs(i, [])
ans = [list(sequence) for sequence in ans_set]  # Set을 다시 리스트로 변환
ans.sort()

for i in ans:
    for j in i:
        print(j, end=" ")
    print()