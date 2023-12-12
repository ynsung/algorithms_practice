# 알파벳 다이아몬드는 정수 길이의 마름모가 여러 개 누적되는 모양이다. 각각의 마름모는 하나의 알파벳 소문자로 그리며, a로 시작해서 z로 끝난다.
# (가운데에서부터) 그리고, z 이후에는 다시 a로 시작한다.
# 알파벳 다이아몬드는 다음과 같이 생겼다.

# a

# .b.
# bab
# .b.

# ..c..
# .cbc.
# cbabc
# .cbc.
# ..c..

# ...d...
# ..dcd..
# .dcbcd.
# dcbabcd
# .dcbcd.
# ..dcd..
# ...d...

# ....e....
# ...ede...
# ..edcde..
# .edcbcde.
# edcbabcde
# .edcbcde.
# ..edcde..
# ...ede...
# ....e....

# .....f.....
# ....fef....
# ...fedef...
# ..fedcdef..
# .fedcbcdef.
# fedcbabcdef
# .fedcbcdef.
# ..fedcdef..
# ...fedef...
# ....fef....
# .....f.....

# 동호는 이런 알파벳 다이아몬드를 타일로 만들어서, 방 바닥을 타일로 모두 채웠다.
# 예를 들어, N = 5인 아스키 다이아몬드를 세로 크기가 17, 가로 크기가 46인 방에 채운다면 다음과 같은 모양이 된다.

# ....e........e........e........e........e.....
# ...ede......ede......ede......ede......ede....
# ..edcde....edcde....edcde....edcde....edcde...
# .edcbcde..edcbcde..edcbcde..edcbcde..edcbcde..
# edcbabcdeedcbabcdeedcbabcdeedcbabcdeedcbabcdee
# .edcbcde..edcbcde..edcbcde..edcbcde..edcbcde..
# ..edcde....edcde....edcde....edcde....edcde...
# ...ede......ede......ede......ede......ede....
# ....e........e........e........e........e.....
# ....e........e........e........e........e.....
# ...ede......ede......ede......ede......ede....
# ..edcde....edcde....edcde....edcde....edcde...
# .edcbcde..edcbcde..edcbcde..edcbcde..edcbcde..
# edcbabcdeedcbabcdeedcbabcdeedcbabcdeedcbabcdee
# .edcbcde..edcbcde..edcbcde..edcbcde..edcbcde..
# ..edcde....edcde....edcde....edcde....edcde...
# ...ede......ede......ede......ede......ede....

# 타일 하나위 위치는 행과 열을 이용해 표현한다. 행은 위에서부터 0행, 1행 이고, 열은 왼쪽부터 0열, 1열이다.
# 동호는 자신의 방의 어떤 부분 직사각형에 쓰여 있는 알파벳이 궁금해졌다.
# N이 주어지고, 동호가 알고 싶어하는 직사각형의 왼쪽 위 좌표 (R1, C1)와 오른쪽 아래 좌표 (R2, C2)가 주어질 때,
# 그 직사각형에 쓰여 있는 알파벳을 출력하는 프로그램을 작성하시오. 동호의 방의 크기는 무한하다. (x, y)는 x행 y열을 의미한다.

# 첫째 줄에 5개의 정수 N, R1, C1, R2, C2가 주어진다.
# (R2 - R1 + 1)줄에 (C2 - C1 + 1)개의 문자를 출력한다.

# 1 ≤ N ≤ 20,000
# 0 ≤ R1 ≤ R2 ≤ 20,000
# 0 ≤ C1 ≤ C2 ≤ 20,000
# 0 ≤ (R2 - R1 + 1) × (C2 - C1 + 1) ≤ 40,000

# --------입력--------
# 5 3 18 10 46
# --------출력--------
# .edcbcde..edcbcde..edcbcde..e
# edcbabcdeedcbabcdeedcbabcdeed
# .edcbcde..edcbcde..edcbcde..e
# ..edcde....edcde....edcde....
# ...ede......ede......ede.....
# ....e........e........e......
# ....e........e........e......
# ...ede......ede......ede.....

from string import ascii_lowercase
ali = list(ascii_lowercase)

import sys
input = sys.stdin.readline

N, r1, c1, r2, c2 = map(int, input().split())
dia = 2*N-1
for i in range(r1, r2+1):
    for j in range(c1, c2+1):
        i %= dia
        j %= dia
        dis = abs(N-1-i) + abs(N-1-j)
        if dis > N-1:
            print(".", end="")
        else:
            print(ali[dis%26], end="")
    print()