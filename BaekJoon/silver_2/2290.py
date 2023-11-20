# 지민이는 새로운 컴퓨터를 샀다. 하지만 새로운 컴퓨터에 사은품으로 온 LC-디스플레이 모니터가 잘 안나오는 것이다.
# 지민이의 친한 친구인 지환이는 지민이의 새로운 모니터를 위해 테스트 할 수 있는 프로그램을 만들기로 하였다.

# 첫째 줄에 두 개의 정수 s와 n이 들어온다. (1 ≤ s ≤ 10, 0 ≤ n ≤ 9,999,999,999)이다.
# n은 LCD 모니터에 나타내야 할 수 이며, s는 크기이다.
# 길이가 s인 '-'와 '|'를 이용해서 출력해야 한다. 각 숫자는 모두 s+2의 가로와 2s+3의 세로로 이루어 진다.
# 나머지는 공백으로 채워야 한다. 각 숫자의 사이에는 공백이 한 칸 있어야 한다.

# --------입력--------
# 2 1234567890

# --------출력--------
#       --   --        --   --   --   --   --   --  
#    |    |    | |  | |    |       | |  | |  | |  | 
#    |    |    | |  | |    |       | |  | |  | |  | 
#       --   --   --   --   --        --   --       
#    | |       |    |    | |  |    | |  |    | |  | 
#    | |       |    |    | |  |    | |  |    | |  | 
#       --   --        --   --        --   --   --  

import sys
s, n = map(str, sys.stdin.readline().split())
s = int(s)
def printNum(line, num):
    if line==1:
        if num==1 or num==4:
            print(" " + " "*s + " ", end=" ")
        else:
            print(" " + "-"*s + " ", end=" ")
    elif line>1 and line<2+s:
        if num==1 or num==2 or num==3 or num==7:
            print(" " + " "*s + "|", end=" ")
        elif num==5 or num==6:
            print("|" + " "*s + " ", end=" ")
        else:
            print("|" + " "*s + "|", end=" ")
    elif line==2+s:
        if num==1 or num==7 or num==0:
            print(" " + " "*s + " ", end=" ")
        else:
            print(" " + "-"*s + " ", end=" ")
    elif line>2+s and line<2*s+3:
        if num==2:
            print("|" + " "*s + " ", end=" ")
        elif num==6 or num==8 or num==0:
            print("|" + " "*s + "|", end=" ")
        else:
            print(" " + " "*s + "|", end=" ")
    else:
        if num==1 or num==4 or num==7:
            print(" " + " "*s + " ", end=" ")
        else:
            print(" " + "-"*s + " ", end=" ")

for i in range(1, 2*s+4):
    for j in n:
        printNum(i,int(j))
    print()