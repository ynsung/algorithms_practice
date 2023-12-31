# 민식이와 준영이는 자기 방에서 문자열을 공부하고 있다.
# 민식이가 말하길 인접해 있는 모든 문자가 같지 않은 문자열을 행운의 문자열이라고 한다고 한다.
# 준영이는 문자열 S를 분석하기 시작했다. 준영이는 문자열 S에 나오는 문자를 재배치하면 서로 다른 행운의 문자열이 몇 개 나오는지 궁금해졌다.
# 만약 원래 문자열 S도 행운의 문자열이라면 그것도 개수에 포함한다.

# 첫째 줄에 문자열 S가 주어진다. S의 길이는 최대 10이고, 알파벳 소문자로만 이루어져 있다.
# 첫째 줄에 위치를 재배치해서 얻은 서로 다른 행운의 문자열의 개수를 출력한다.

# --------입력--------
# aabbbaa

# --------출력--------
# 1

import sys
from collections import Counter

def backTracking(pre, l):
    answer = 0

    # 행운의 문자열이므로 1를 리턴
    if l == len(s):
        return 1

    # 반복문을 통해 단어를 확인
    for k in cnt.keys():
        # 현재 단어가 이전 단어일 경우와 현재 단어의 개수가 0일 경우 다음 단어를 확인한다.
        if k == pre or cnt[k] == 0:
            continue

        cnt[k] -= 1 # 현재 단어의 개수를 감소
        answer += backTracking(k, l + 1) # 백트래킹 후 리턴 받은 수를 answer에 더한다.
        cnt[k] += 1 # 현재 단어의 개수를 증가

    # answer 리턴
    return answer

s = list(map(str, sys.stdin.readline().strip()))
cnt = Counter(s) # 문자의 개수를 딕셔너리로 변환
print(backTracking('', 0))

