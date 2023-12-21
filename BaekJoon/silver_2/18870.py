# 수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
# Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.
# X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

# 첫째 줄에 N이 주어진다.
# 둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

# 첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

# 제한
# 1 ≤ N ≤ 1,000,000
# -109 ≤ Xi ≤ 109

# --------입력--------
# 5
# 2 4 -10 4 -9
# --------출력--------
# 2 3 0 3 1

import sys
n = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))
di, se = {}, list(set(li))
se.sort()
num = 0
for i in se:
    di[i] = num
    num += 1
for i in li:
    print(di[i], end=" ")