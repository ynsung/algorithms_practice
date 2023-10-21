/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.


첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
입력으로 주어지는 간선은 양방향이다.
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

--------입력--------
4 5 1
1 2
1 3
1 4
2 4
3 4

--------출력--------
1 2 4 3
1 2 3 4
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1001

bool visited[MAX_SIZE];
int node[MAX_SIZE][MAX_SIZE];
int q[MAX_SIZE];

void dfs(int v, int n){
    visited[v] = true;
    printf("%d ", v);

    for(int i=1; i<=n; i++){
        if(!visited[i] && node[v][i]==1)
            dfs(i, n);
    }
}

void bfs(int v, int n){
    int front = 0, rear = 0, pop;
    printf("%d ", v);
    visited[v] = true;
    q[0] = v;
    rear++;
    while(front < rear){
        pop = q[front++];
        for(int i=1; i<=n; i++){
            if(node[pop][i]==1 && !visited[i]){
                printf("%d ", i);
                q[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    for(int i=1; i<=n; i++)
        visited[i] = false;
    
    while(m--){
        int i, j;
        scanf("%d %d", &i, &j);
        node[i][j] = 1;
        node[j][i] = 1;
    }
    dfs(v, n);
    printf("\n");
    
    for(int i=1; i<=n; i++)
        visited[i] = false;
    
    bfs(v, n);
    return 0;
}