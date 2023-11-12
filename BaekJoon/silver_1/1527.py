# 은민이는 4와 7을 좋아하고, 나머지 숫자는 싫어한다. 금민수는 어떤 수가 4와 7로만 이루어진 수를 말한다.
# A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력하는 프로그램을 작성하시오.

# 첫째 줄에 A와 B가 주어진다. A는 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다.
# B는 A보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다.
# 첫째 줄에 A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력한다.

# --------입력--------
# 1 10

# --------출력--------
# 2

import sys
a,b = map(int,sys.stdin.readline().split())
a = str(a-1)
b = str(b)

def minsu(num):
    cnt = 0
    tmp = 0
    for i in range(1, len(num)):
        cnt += 2**i

    for i in range(0, len(num)):
        if num[i]=='7':
            tmp += 2**(len(num)-1-i)
            if i == len(num)-1:
                tmp += 1
        elif num[i]>'7':
            tmp += 2**(len(num)-i)
            break
        elif num[i]<'4':
            break
        elif num[i]=='5' or num[i]=='6':
            tmp += 2**(len(num)-1-i)
            break
        else:
            if i == len(num)-1:
                tmp += 1           
    return int(cnt+tmp)
print(minsu(b)-minsu(a))
