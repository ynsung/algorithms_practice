# 메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다. 지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다.
# 지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다.
# 지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다.
# 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다.
# 어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.

# 지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때, 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요.
# 만약 지낼 수 있는 무인도가 없다면 -1을 배열에 담아 return 해주세요.

# 3 ≤ maps의 길이 ≤ 100
# 3 ≤ maps[i]의 길이 ≤ 100
# maps[i]는 'X' 또는 1 과 9 사이의 자연수로 이루어진 문자열입니다.
# 지도는 직사각형 형태입니다.

# maps	                              result
# ["X591X","X1X5X","X231X", "1XXX1"]	[1, 1, 27]
# ["XXX","XXX","XXX"]	                [-1]

import sys
sys.setrecursionlimit(10 ** 6)

cnt = 0
r, c = 0, 0
def dfs(x, y, maps, visited):
    global cnt, r, c
    cnt += int(maps[x][y])
    visited[x][y] = True
    dx, dy = [-1, 0, 1, 0], [0, -1, 0, 1]
    
    for k in range(4):
        X = x+dx[k]
        Y = y+dy[k]
        if 0<=X<r and 0<=Y<c and maps[X][Y]!='X' and visited[X][Y]==False:
            dfs(X,Y,maps, visited)

def solution(maps):
    ans, noans = [], [-1]
    global r, c
    r, c = len(maps), len(maps[0])
    global cnt
    visited = [[False]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if maps[i][j] != 'X' and visited[i][j] == False:
                dfs(i, j, maps, visited)
                ans.append(cnt)   
                cnt = 0
    ans.sort()
    return noans if len(ans)==0 else ans