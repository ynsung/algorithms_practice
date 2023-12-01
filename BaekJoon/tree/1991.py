# 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal),
# 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

# 예를 들어 위와 같은 이진 트리가 입력되면,

# 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
# 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
# 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
# 가 된다.


# 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
# 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
# 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.
# 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

# --------입력--------
# 7
# A B C
# B D .
# C E F
# E . .
# F . G
# D . .
# G . .

# --------출력-------- 
# ABDCEFG
# DBAECFG
# DBEGFCA

import sys
n = int(sys.stdin.readline())
tree = dict()

# 반복문을 통해 트리 생성
for i in range(n):
    root, left, right = map(str, sys.stdin.readline().split())
    tree[root] = left, right

# 전위 순회
def preorder(v):
    if v != ".": # 자식이 있다면
        print(v, end="") # 루트 노드 출력
        preorder(tree[v][0]) # 재귀적으로 왼쪽 노드 탐색
        preorder(tree[v][1]) # 재귀적으로 오른쪽 노드 탐색

# 중위 순회
def inorder(v):
    if v != ".": # 자식이 있다면
        inorder(tree[v][0]) # 재귀적으로 왼쪽 노드 탐색
        print(v, end="") # 루트 노드 출력
        inorder(tree[v][1]) # 재귀적으로 오른쪽 노드 탐색

# 후위 순회
def postorder(v):
    if v != ".": # 자식이 있다면
        postorder(tree[v][0]) # 재귀적으로 왼쪽 노드 탐색
        postorder(tree[v][1]) # 재귀적으로 오른쪽 노드 탐색
        print(v, end="") # 루트 노드 출력

preorder('A')
print()
inorder('A')
print()
postorder('A')