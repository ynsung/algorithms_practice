# N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

# N개의 자연수 중에서 M개를 고른 수열
# 같은 수를 여러 번 골라도 된다.
# 고른 수열은 비내림차순이어야 한다.
# 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

# 첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
# 둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
# 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
# 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

# --------입력--------
# 3 1
# 4 4 2
# --------출력--------
# 2
# 4

N,M=map(int,input().split())
lst=list(map(int,input().split()))
dup_check=[]

def solve(num,start,ans):
    if len(ans)==num:
        for i in ans:
            print(lst[i],end=' ')
        print()
        return
    for i in range(start,len(lst)):
        solve(num,i,ans+[i])

lst=list(set(lst))
lst.sort()
for i in range(len(lst)):
    solve(M,i,[i])