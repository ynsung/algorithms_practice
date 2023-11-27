# 어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
# 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자.
# 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

# 첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다.
# 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)
# 첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

# --------입력--------
# 6 5
# 1 1 0 1 1
# 0 1 1 0 0
# 0 0 0 0 0
# 1 0 1 1 1
# 0 0 1 1 1
# 0 0 1 1 1

# --------출력--------
# 4
# 9

from collections import deque

def bfs(x, y):
    a[x][y] = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    w = 1
    q = deque()
    q.append([x, y])
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if 0 <= nx < n and 0 <= ny < m and a[nx][ny] == 1:
                q.append([nx, ny])
                a[nx][ny] = 0
                w += 1
    return w

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
cnt = 0
ans = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == 1:
            cnt += 1
            ans = max(bfs(i, j), ans)
print(cnt)
print(ans)