/*
개구리가 일렬로 놓여 있는 징검다리 사이를 폴짝폴짝 뛰어다니고 있다.
징검다리에는 숫자가 각각 쓰여 있는데, 이 개구리는 매우 특이한 개구리여서
어떤 징검다리에서 점프를 할 때는 그 징검다리에 쓰여 있는 수의 배수만큼 떨어져 있는 곳으로만 갈 수 있다.

이 개구리는 a번째 징검다리에서 b번째 징검다리까지 가려고 한다.
이 개구리가 a번째 징검다리에서 시작하여 최소 몇 번 점프를 하여 b번째 징검다리까지 갈 수 있는지를 알아보는 프로그램을 작성하시오.

첫째 줄에 징검다리의 개수 N(1≤N≤10,000)이 주어지고, 이어서 각 징검다리에 쓰여 있는 N개의 정수가 주어진다.
그 다음 줄에는 N보다 작거나 같은 자연수 a, b가 주어지는 데, 이는 개구리가 a번 징검다리에서 시작하여 b번 징검다리에 가고 싶다는 뜻이다
 징검다리에 쓰여있는 정수는 10,000보다 작거나 같은 자연수이다.
첫째 줄에 개구리가 a번 징검다리에서 b번 징검다리로 최소 몇 번 점프하여 갈 수 있는 지를 출력하시오.
a에서 b로 갈 수 없는 경우에는 -1을 출력한다.

--------입력--------
5
1 2 2 1 2
1 5

--------출력--------
1

*/
#include <stdio.h>
#include <stdbool.h>

int n, from, to, front = 0, rear = 0;
int road[10001], q[10001], record[10001] = {0, };
bool visited[10001];

void bfs(int from, int to){
    q[++rear] = from;
    visited[from] = true;

    while(front < rear){
        int pop = q[++front];
        if(pop == to)
            return;
        
        for(int i=pop+road[pop]; i<= n; i+=road[pop]){
            if(!visited[i]){
                record[i] = record[pop] + 1;
                q[++rear] = i;
                visited[i] = true;
            }
        }

        for(int i=pop-road[pop]; i>=1; i-=road[pop]){
            if(!visited[i]){
                record[i] = record[pop] + 1;
                q[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &road[i]);
    scanf("%d %d", &from, &to);
    
    if(from == to){
        printf("0");
        return 0;
    }

    for(int i=1; i<=n; i++)
        visited[i] = false;
    
    bfs(from, to);
    if(record[to] == 0)
        record[to] = -1;
    printf("%d", record[to]); 
    return 0;
}