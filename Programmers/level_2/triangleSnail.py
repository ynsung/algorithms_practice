# 정수 n이 매개변수로 주어집니다.
# 다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후,
# 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.

# n은 1 이상 1,000 이하입니다.

# n	result
# 4	[1,2,9,3,10,8,4,5,6,7]
# 5	[1,2,12,3,13,11,4,14,15,10,5,6,7,8,9]
# 6	[1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]

def solution(n):
    d = {}
    for i in range(1,n+1):
        d[i] = [0]*i
    
    t_len = n
    st_top = 1
    idx = 0
    ldx = 0
    while t_len > 1:
        m_len = st_top-1
        bdx = ldx+1
        for i in range(st_top, st_top+t_len*3-3):
            if i-m_len <= t_len:
                idx += 1
                d[idx][ldx] = i
            elif i-m_len < 2*t_len:
                d[idx][bdx] = i
                bdx += 1
            else:
                idx -= 1
                rdx = idx-ldx-1
                d[idx][rdx] = i
        st_top += t_len*3-3
        t_len -= 3
        ldx += 1
        
    if t_len == 1:
        idx += 1
        d[idx][ldx] = st_top
        
    answer = []
    for i in range(1, n+1):
        for j in d[i]:
            answer.append(j)
    return answer