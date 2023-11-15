import sys
input = sys.stdin.readline

n = int(input().rstrip())
balls = []
cnt = 0
tmp = 0
tot = 0
while n >= tot:
    tmp += 1
    cnt += tmp
    tot += cnt
    balls.append(tot)
print(balls)
MAX = sys.maxsize
dp = [MAX]*(n+1)
for i in range(1, n+1):
    # print("대포알 {}개를 탐색중".format(i))
    for b in balls:
        if b >= i:
            if b == i:
                # print("{}개로 사면체 하나 만들 수 있으므로 dp[{}]=1".format(b, i))
                dp[i] = 1
            # print("b({})가 i({})보다 크거나 같으므로 break하고 i+1".format(b, i))
            break
        # print("dp[{}]와 1+dp[{}-{}]를 비교 -> dp[{}]=min({}, {})".format(i, i, b, i, dp[i], 1+dp[i-b]))
        dp[i] = min(dp[i],1 + dp[i-b]) #포탄이 n개 일 때 b만큼의 포탄을 가진 사면체 + 1
        # print("for문 돌면서 다음 b 검사")
print(dp[n])