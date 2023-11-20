# N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다.

# N=5일 때의 예를 보자.

# 12	7	  9	  15	5
# 13	8	  11	19	6
# 21	10	26	31	16
# 48	14	28	35	25
# 52	20	32	41	49

# 이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.


# 첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다.
# 표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다.
# 첫째 줄에 N번째 큰 수를 출력한다.

# --------입력--------
# 5
# 12 7 9 15 5
# 13 8 11 19 6
# 21 10 26 31 16
# 48 14 28 35 25
# 52 20 32 41 49

# --------출력--------
# 35

import sys, heapq

input = sys.stdin.readline
n = int(input())
q = []
for i in range(n):
	num_list = list(map(int, input().split()))
	if not q: # q에 아무것도 없는 첫번째 입력 시
		for num in num_list:
			heapq.heappush(q, num) # min_heap 구조로 q 채우기
	else:
		for num in num_list: # q에 값이 있을 시 늘 q의 길이를 n으로 유지하기
			if q[0] < num: # q 최솟값보다 현재 숫자가 클 경우 n번째로 큰 수가 바뀌어야 하기 때문에
				heapq.heappush(q, num) # 현재 숫자를 push 하고
				heapq.heappop(q) # 기존 최솟값 pop
print(q[0])