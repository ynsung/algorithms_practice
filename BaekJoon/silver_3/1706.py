# 동혁이는 크로스워드 퍼즐을 좋아한다. R×C 크기의 크로스워드 퍼즐을 생각해 보자.
# 이 퍼즐은 R×C 크기의 표로 이루어지는데, 퍼즐을 다 풀면 금지된 칸을 제외하고는 각 칸에 알파벳이 하나씩 적혀 있게 된다.
# 아래는 R = 5, C = 5 인 경우 다 푼 퍼즐의 한 예이다. 검은 칸은 금지된 칸이다.

# 세로 또는 가로로 연속되어 있고, 더 이상 확장될 수 없는 낱말이 퍼즐 내에 존재하는 단어가 된다.
# 위의 퍼즐과 같은 경우, 가로 낱말은 good, an, messy, it, late의 5개가 있고, 세로 낱말은 game, one, sit, byte의 4개가 있다.
# 이 중 사전식 순으로 가장 앞서 있는 낱말은 an이다.

# 다 푼 퍼즐이 주어졌을 때, 퍼즐 내에 존재하는 모든 낱말 중 사전식 순으로 가장 앞서 있는 낱말을 구하는 프로그램을 작성하시오.


# 첫째 줄에는 퍼즐의 R과 C가 빈 칸을 사이에 두고 주어진다. (2 ≤ R, C ≤ 20) 이어서 R개의 줄에 걸쳐 다 푼 퍼즐이 주어진다.
# 각 줄은 C개의 알파벳 소문자 또는 금지된 칸을 나타내는 #로 이루어진다. 낱말이 하나 이상 있는 입력만 주어진다.
# 첫째 줄에 사전식 순으로 가장 앞서 있는 낱말을 출력한다.

# --------입력--------
# 4 5
# adaca
# da##b
# abb#b
# abbac
# --------출력--------
# abb

r, c = map(int, input().split())
li = [input() for _ in range(r)]
di = []
for i in range(r):
    tmp = ""
    for j in range(c):
        if li[i][j] != '#':
            tmp += li[i][j]
            if j==c-1 and len(tmp)>1:
                di.append(tmp)
                tmp=""
        else:
            if len(tmp) > 1:
                di.append(tmp)
            tmp = ""
for j in range(c):
    tmp = ""
    for i in range(r):
        if li[i][j] != '#':
            tmp += li[i][j]
            if i==r-1 and len(tmp)>1:
                di.append(tmp)
                tmp=""
        else:
            if len(tmp)>1:
                di.append(tmp)
            tmp = ""
di.sort()
print(di[0])