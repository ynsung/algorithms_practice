# 팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다.
# 마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.

# 목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업을 해야 한다.
# lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다.
# 우리는 다음과 같은 두 종류의 작업을 할 수 있다.

# 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
# 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
# 1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다.
# ‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

# 단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다.
# 땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

# 첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)
# 둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다.
# 땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.
# 첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.

# --------입력--------
# 3 4 99
# 0 0 0 0
# 0 0 0 0
# 0 0 0 1
# --------출력--------
# 2 0

import sys 
input = sys.stdin.readline

# 모든 땅의 높이를 h로 만드는데 걸리는 시간을 구하는 함수 
def get_time(h):
    add_num = 0   # 삽입할 블록의 개수 
    erase_num = 0 # 제거할 블록의 개수 

    # 0부터 256까지 각 높이의 경우를 모두 탐색
    for i in range(257):
        # 높이의 개수와 h와의 차를 구해줌 
        n, tmp = nums[i], i - h 
        # 개수가 0이라면 넘어감 
        if n == 0: continue 
        # 높이의 차가 음수일 경우 삽입할 블록의 개수 구해줌 
        if tmp < 0:
            add_num += (-tmp) * n 
        # 높이의 차가 양수일 경우 제거할 블록의 개수 구해줌 
        else:
            erase_num += tmp * n 
    
    # 만약 인벤토리에서 사용할 수 있는 블록이 있을 경우 
    if (erase_num + b) - add_num >= 0:
        # 시간을 구해줌 
        time = erase_num * 2 + add_num 
        return time 
    # 사용할 수 있는 블록이 없을 경우 
    else:
        return 1e9 + 1
            
n, m, b = map(int,input().split())

# 땅 높이 종류의 각 개수를 구해줌 
nums = [0] * 257 
for i in range(n):
    for j in list(map(int,input().split())):
        nums[j] += 1 

# 최소 시간과 그 때의 높이를 저장할 변수 
ans = 1e9 
height = 0

# 0부터 256까지 모든 땅을 각 높이로 만드는 시간을 구해줌 
for h in range(257):
    # 시간을 계산 
    time = get_time(h)
    # 최소값과 그 때의 땅 높이를 구해줌  
    if time <= ans:
        ans = time 
        height = h 

print(ans, height)