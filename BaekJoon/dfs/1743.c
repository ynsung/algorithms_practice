// 첫째 줄에 통로의 세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100) 그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ N×M)이 주어진다. 
// 그리고 다음 K개의 줄에 음식물이 떨어진 좌표 (r, c)가 주어진다.
// 좌표 (r, c)의 r은 위에서부터, c는 왼쪽에서부터가 기준이다. 입력으로 주어지는 좌표는 중복되지 않는다.

// 첫째 줄에 음식물 중 가장 큰 음식물의 크기를 출력하라.

// --------입력-------- 
// 3 4 5
// 3 2
// 2 2
// 3 1
// 2 3
// 1 1

// --------출력--------
// 4

#include <stdio.h>
#include <stdbool.h>

int matrix[100][100] = {0, };
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int size = 0, ans = 0;
int r, c, t;

void bfs(int x, int y){
    visited[x][y] = true;
    size++;

    for(int i=0; i<4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>=0 && X<r && Y>=0 && Y<c && !visited[X][Y] && matrix[X][Y]==1){
            bfs(X, Y);
        }
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        matrix[x-1][y-1] = 1;
    }
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            visited[i][j] = false;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            if (!visited[i][j] && matrix[i][j]==1){
                bfs(i, j);
                ans = ans > size ? ans : size;
                size = 0;
            }
        }
    printf("%d", ans);
    return 0;
}