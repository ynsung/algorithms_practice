/*
전쟁은 어느덧 전면전이 시작되었다. 결국 전투는 난전이 되었고, 우리 병사와 적국 병사가 섞여 싸우게 되었다.
그러나 당신의 병사들은 흰색 옷을 입고, 적국의 병사들은 파란색 옷을 입었기 때문에 서로가 적인지 아군인지는 구분할 수 있다.
문제는 같은 팀의 병사들은 모이면 모일수록 강해진다는 사실이다.

N명이 뭉쳐있을 때는 N2의 위력을 낼 수 있다. 과연 지금 난전의 상황에서는 누가 승리할 것인가?
단, 같은 팀의 병사들이 대각선으로만 인접한 경우는 뭉쳐 있다고 보지 않는다.

첫째 줄에는 전쟁터의 가로 크기 N, 세로 크기 M(1 ≤ N, M ≤ 100)이 주어진다.
그 다음 두 번째 줄에서 M+1번째 줄에는 각각 (X, Y)에 있는 병사들의 옷색이 띄어쓰기 없이 주어진다.
모든 자리에는 병사가 한 명 있다. B는 파란색, W는 흰색이다. 당신의 병사와 적국의 병사는 한 명 이상 존재한다.
첫 번째 줄에 당신의 병사의 위력의 합과 적국의 병사의 위력의 합을 출력한다.

--------입력--------
5 5
WBWWW
WWWWW
BBBBB
BBBWW
WWWWW

--------출력--------
130 65
*/
#include <stdio.h>
#include <stdbool.h>

int n, m, w, b;
char a[101][101];
bool check[100][100];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y, char c)
{
    int ret = 1;
    check[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (!check[nx][ny] && a[nx][ny] == c)
            ret += dfs(nx, ny, c);
    }
    return ret;
}

int main()
{
    scanf("%d %d", &m, &n); // m: 가로 , n : 세로
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!check[i][j])
            {
                int k = dfs(i, j, a[i][j]);
                if (a[i][j] == 'W')
                    w += k * k;
                else
                    b += k * k;
            }
        }
    }
    printf("%d %d\n", w, b);
    return 0;
}