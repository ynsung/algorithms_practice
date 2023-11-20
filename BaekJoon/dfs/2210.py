# 5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다.
# 이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다.
# 이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.
# 숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.


# 다섯 개의 줄에 다섯 개의 정수로 숫자판이 주어진다.
# 첫째 줄에 만들 수 있는 수들의 개수를 출력한다.

# --------입력--------
# 1 1 1 1 1
# 1 1 1 1 1
# 1 1 1 1 1
# 1 1 1 2 1
# 1 1 1 1 1

# --------출력--------
# 15

import sys
li = [list(map(str, sys.stdin.readline().split())) for _ in range(5)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
d = {}

def dfs(x, y, num):
    num += li[x][y]
    if len(num) == 6:
        d[num] = True
        return
    
    for i in range(0, 4):
        X = x + dx[i]
        Y = y + dy[i]
        if X>=0 and X<=4 and Y>=0 and Y<=4:
            dfs(X, Y, num)

for i in range(0, 5):
    for j in range(0, 5):
        ans = ""
        dfs(i, j, ans)
print(len(d))