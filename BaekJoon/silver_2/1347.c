/*
홍준이는 미로 안의 한 칸에 남쪽을 보며 서있다. 미로는 직사각형 격자모양이고, 각 칸은 이동할 수 있거나, 벽을 포함하고 있다.
모든 행과 열에는 적어도 하나의 이동할 수 있는 칸이 있다. 홍준이는 미로에서 모든 행과 열의 이동할 수 있는 칸을 걸어다녔다.
그러면서 자신의 움직임을 모두 노트에 쓰기로 했다. 홍준이는 미로의 지도를 자기 노트만을 이용해서 그리려고 한다.

입력으로 홍준이가 적은 내용을 나타내는 문자열이 주어진다. 각 문자 하나는 한 번의 움직임을 말한다.
‘F’는 앞으로 한 칸 움직인 것이고, ‘L'과 ’R'은 방향을 왼쪽 또는 오른쪽으로 전환한 것이다. 즉, 90도를 회전하면서, 위치는 그대로인 것이다.

첫째 줄에 홍준이가 적은 내용의 길이가 주어진다. 길이는 0보다 크고, 50보다 작다. 둘째 줄에 홍준이가 적은 내용이 내용이 주어진다.
첫째 줄에 미로 지도를 출력한다. ‘.’은 이동할 수 있는 칸이고, ‘#’는 벽이다.

--------입력-------- 
5
RRFRF

--------출력-------- 
..
.#
*/
#include <stdio.h>
#include <stdbool.h>

bool map[102][102];
int r_s = 51, r_e = 51, c_s = 51, c_e = 51;
int r[4] = {1, 0, -1, 0};
int c[4] = {0, -1, 0, 1};

int main() {
    int n, dir = 0, x = 51, y = 51;
    char str[51];
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++)
            map[i][j] = false;
    }
    scanf("%d %s", &n, str);
    map[x][y] = true;
    for(int i=0; i<n; i++){
        if(str[i] == 'L'){
            dir--;
            if(dir < 0) dir += 4;
        }
        else if(str[i] == 'R'){
            dir = (dir+1)%4;
        }
        else{
            x += r[dir];
            y += c[dir];
            map[x][y] = true;
            r_s = r_s < x ? r_s : x;
            r_e = r_e > x ? r_e : x;
            c_s = c_s < y ? c_s : y;
            c_e = c_e > y ? c_e : y;
        }
    }
    for(int i=r_s; i<=r_e; i++){
        for(int j=c_s; j<=c_e; j++){
            if(!map[i][j]) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}