# nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

# 첫째 줄에 정수 n, m이 들어온다. (0 <= m <= n 2,000,000,000, n!=0)
# 첫째 줄에 nCm의 끝자리 0의 개수를 출력한다.

# --------입력--------
# 25 12

# --------출력--------
# 2

import sys
n, m = map(int, sys.stdin.readline().split())

def count2(N):
    if N < 2:
        return 0
    count = 0
    while N >= 2:
        count += N//2
        N = N//2
    return count

def count5(N):
    if N < 5:
        return 0
    count = 0
    while N >= 5:
        count += N//5
        N //= 5
    return count

two_count = count2(n) - count2(n-m) - count2(m)
five_count = count5(n) - count5(n-m) - count5(m)
print(min(two_count, five_count))