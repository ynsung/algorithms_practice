# 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
# 단, 대문자와 소문자를 구분하지 않는다.

# 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.
# 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

# --------입력--------
# Mississipi

# --------출력--------
# ?
arr = input()
li = list(arr.upper())
dict = {}
for i in li:
    if i in dict:
        dict[i] += 1
    else:
        dict[i] = int(1)
f = int(0)
g = ""
for i in dict:
    if dict[i] == max(dict.values()):
        f += 1
        g = i
    if f == 2:
        break
if f>1:
    print("?")
else:
    print(g)