# 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

# 길이가 짧은 것부터
# 길이가 같으면 사전 순으로
# 단, 중복된 단어는 하나만 남기고 제거해야 한다.


# 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000)
# 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
# 주어지는 문자열의 길이는 50을 넘지 않는다.
# 조건에 따라 정렬하여 단어들을 출력한다.

# --------입력--------
# 13
# but
# i
# wont
# hesitate
# no
# more
# no
# more
# it
# cannot
# wait
# im
# yours

# --------출력--------
# i
# im
# it
# no
# but
# more
# wait
# wont
# yours
# cannot
# hesitate

n = int(input())
dict = {}
for i in range(n):
    arr = input()
    leng = len(arr)
    if leng in dict:
        if arr not in dict[leng]:
            dict[leng].append(arr)
    else:
        dict[leng] = []
        dict[leng].append(arr)
for i in dict:
    dict[i].sort()
li = []
for i in range(max(dict.keys())+1):
    if i in dict:
        for j in range(len(dict[i])):
            print(dict[i][j])