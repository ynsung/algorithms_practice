# 우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 이러한 촌수는 다음과 같은 방식으로 계산된다.
# 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다.
# 예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
# 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.

# 사람들은 1, 2, 3, …, n (1 ≤ n ≤ 100)의 연속된 번호로 각각 표시된다.
# 입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다.
# 그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다.
# 이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
# 각 사람의 부모는 최대 한 명만 주어진다.
# 입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.

# --------입력--------
# 9
# 7 3
# 7
# 1 2
# 1 3
# 2 7
# 2 8
# 2 9
# 4 5
# 4 6
# --------출력--------
# 3

import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
x, y = map(int, input().split())
m = int(input())
di = {}
for _ in range(m):
    a, b = map(int, input().split())
    if a in di:
        di[a].append(b)
    else:
        di[a] = [b]
    if b in di:
        di[b].append(a)
    else:
        di[b] = [a]
q = deque([(x,0)])
flag = True
visited = [False for i in range(n+1)]
while q:
    found = q.popleft()
    if found[0]==y:
        print(found[1])
        flag = False
        break
    visited[found[0]] = True
    for i in di[found[0]]:
        if not visited[i]:
            q.append((i,found[1]+1))
if flag:
    print(-1)