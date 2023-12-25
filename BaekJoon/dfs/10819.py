# N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.
# |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

# 첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.
# 첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

# --------입력--------
# 6
# 20 1 15 8 4 10
# --------출력--------
# 62

def dfs(idx,newli):
    global ans
    visited[idx] = True
    newli.append(li[idx])
    if len(newli)==n:
        tmp = 0
        for i in range(n-1):
            tmp += abs(newli[i]-newli[i+1])
        ans = max(ans,tmp)
        visited[idx] = False
        return
    for i in range(n):
        if not visited[i]:
            dfs(i,newli)
            newli.pop()
    visited[idx] = False

import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))
visited = [False for _ in range(n)]
ans = 0
for i in range(n):
    dfs(i,[])
print(ans)