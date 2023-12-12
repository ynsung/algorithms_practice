# 두 정수 left와 right가 매개변수로 주어집니다.
# left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.

# 1 ≤ left ≤ right ≤ 1,000

# left	right	  result
# 13	  17	    43
# 24	  27	    52

def solution(left, right):
    ans = 0
    for i in range(left, right+1):
        cnt = 2
        for j in range(2,int(i**(1/2))+1):
            if i%j==0:
                cnt += 2
        if i == int(i**(1/2))**2:
            cnt -= 1
        ans = ans+i if cnt%2==0 else ans-i
    return ans