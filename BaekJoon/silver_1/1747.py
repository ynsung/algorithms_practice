# 어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다.
# 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
# 어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.

# 첫째 줄에 N이 주어진다.
# 첫째 줄에 조건을 만족하는 수를 출력한다.

# --------입력--------
# 31

# --------출력--------
# 101

import math

def is_prime_num(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False
    return True if n!=1 else False

def is_palindrome(n):
    li = n[:len(n)//2]
    ri = n[len(n)//2:]
    ri.reverse()
    if len(li) != len(ri):
        ri.pop()
    return True if ri == li else False

num = int(input())
n = list(str(num))

while True:
    if is_palindrome(n) and is_prime_num(num):
        print(num)
        break
    num += 1
    n = list(str(num))