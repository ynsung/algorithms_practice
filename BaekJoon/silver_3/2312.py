# 양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

# 첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 주어진다.
# 각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 한다.

# --------입력--------
# 2
# 6
# 24
# --------출력--------
# 2 1
# 3 1
# 2 3
# 3 1
import sys
n = int(sys.stdin.readline())
for _ in range(n):
    num = int(sys.stdin.readline())
    div = 1
    while num>=2:
        cnt = 0
        div += 1
        while num%div==0:
            num //= div
            cnt += 1
        if cnt>0:
            print(div, cnt)