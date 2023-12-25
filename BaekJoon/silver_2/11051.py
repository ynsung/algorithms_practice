# 자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

# 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)
# (N K)를 10,007로 나눈 나머지를 출력한다.

# --------입력--------
# 5 2
# --------출력--------
# 10
import sys
n, k = map(int, sys.stdin.readline().split())
for i in range(n-1,n-k,-1):
    n *= i
for i in range(k-1,1,-1):
    k *= i
if k!=0:
    print((n//k)%10007)
else:
    print(1)