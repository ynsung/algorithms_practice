# 길이가 같은 두 개의 큐가 주어집니다.
# 하나의 큐를 골라 원소를 추출(pop)하고, 추출된 원소를 다른 큐에 집어넣는(insert) 작업을 통해 각 큐의 원소 합이 같도록 만들려고 합니다.
# 이때 필요한 작업의 최소 횟수를 구하고자 합니다. 한 번의 pop과 한 번의 insert를 합쳐서 작업을 1회 수행한 것으로 간주합니다.

# 큐는 먼저 집어넣은 원소가 먼저 나오는 구조입니다. 이 문제에서는 큐를 배열로 표현하며, 원소가 배열 앞쪽에 있을수록 먼저 집어넣은 원소임을 의미합니다.
# 즉, pop을 하면 배열의 첫 번째 원소가 추출되며, insert를 하면 배열의 끝에 원소가 추가됩니다.
# 예를 들어 큐 [1, 2, 3, 4]가 주어졌을 때, pop을 하면 맨 앞에 있는 원소 1이 추출되어 [2, 3, 4]가 되며, 이어서 5를 insert하면 [2, 3, 4, 5]가 됩니다.

# 다음은 두 큐를 나타내는 예시입니다.

# queue1 = [3, 2, 7, 2]
# queue2 = [4, 6, 5, 1]
# 두 큐에 담긴 모든 원소의 합은 30입니다. 따라서, 각 큐의 합을 15로 만들어야 합니다. 예를 들어, 다음과 같이 2가지 방법이 있습니다.

# queue2의 4, 6, 5를 순서대로 추출하여 queue1에 추가한 뒤, queue1의 3, 2, 7, 2를 순서대로 추출하여 queue2에 추가합니다.
# 그 결과 queue1은 [4, 6, 5], queue2는 [1, 3, 2, 7, 2]가 되며, 각 큐의 원소 합은 15로 같습니다. 이 방법은 작업을 7번 수행합니다.
# queue1에서 3을 추출하여 queue2에 추가합니다. 그리고 queue2에서 4를 추출하여 queue1에 추가합니다.
# 그 결과 queue1은 [2, 7, 2, 4], queue2는 [6, 5, 1, 3]가 되며, 각 큐의 원소 합은 15로 같습니다.
# 이 방법은 작업을 2번만 수행하며, 이보다 적은 횟수로 목표를 달성할 수 없습니다.
# 따라서 각 큐의 원소 합을 같게 만들기 위해 필요한 작업의 최소 횟수는 2입니다.

# 길이가 같은 두 개의 큐를 나타내는 정수 배열 queue1, queue2가 매개변수로 주어집니다.
# 각 큐의 원소 합을 같게 만들기 위해 필요한 작업의 최소 횟수를 return 하도록 solution 함수를 완성해주세요.
# 단, 어떤 방법으로도 각 큐의 원소 합을 같게 만들 수 없는 경우, -1을 return 해주세요.

# 1 ≤ queue1의 길이 = queue2의 길이 ≤ 300,000
# 1 ≤ queue1의 원소, queue2의 원소 ≤ 109
# 주의: 언어에 따라 합 계산 과정 중 산술 오버플로우 발생 가능성이 있으므로 long type 고려가 필요합니다.

# queue1	        queue2	        result
# [3, 2, 7, 2]	  [4, 6, 5, 1]	  2
# [1, 2, 1, 2]	  [1, 10, 1, 2]	  7
# [1, 1]	        [1, 5]	        -1

def solution(queue1, queue2):
    answer = -1
    sq = queue1 + queue2
    fsum = sum(sq)
    if fsum%2 !=0:
        return -1
    
    hsum = fsum//2
    sq += queue1
    len_sq = len(sq)
    sdx, edx, nsum = -1, -1, 0
    li = []
    
    while sdx <= edx < len_sq-1:
        if nsum<hsum:
            edx += 1
            nsum += sq[edx]
        elif nsum>hsum:
            sdx += 1
            nsum -= sq[sdx]
        else:
            tmp = [sdx+1, edx]
            li.append(tmp)
            edx += 1
            nsum += sq[edx]
    
    lq1, lq2 = len(queue1), len(queue2)
    ans = []
    for i in li:
        sdx, edx = i[0], i[1]
        if sdx <= edx < lq1: # q1 안에 있는 경우
            if edx == lq1-1:
                ans.append(sdx+1)
            else:
                ans.append(edx+1 + lq2 + sdx+1)
        elif sdx < lq1 <= edx < lq1+lq2: # q1 q2에 걸친 경우
            ans.append(sdx + edx-lq1+1)
        elif lq1 <= sdx <= edx < lq1+lq2: # q2 안에 있는 경우
            if edx == lq1+lq2-1:
                ans.append(sdx-lq1)
            else:
                ans.append(edx-lq1+1 + lq1 + sdx-lq1)
        elif lq1 <= sdx < lq1+lq2 <= edx: # q2 q1에 걸친 경우
            ans.append(sdx-lq1 + edx-lq1-lq2+1)
    return min(ans) if len(ans)!=0 else -1