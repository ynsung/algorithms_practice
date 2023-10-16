/*
한수는 캠프를 마치고 집에 돌아가려 한다. 한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 

그리고 한수는 집에 돌아가는 방법이 다양하다. 단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다.

      cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f 
      bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde 
      a...  abcd  abc.  abcd  a...  a.gh  abc. 
거리 :  6     6     6     8     8    10    6

위 예제는 한수가 집에 돌아갈 수 있는 모든 경우를 나타낸 것이다. T로 표시된 부분은 가지 못하는 부분이다.

문제는 R x C 맵에 못가는 부분이 주어지고 거리 K가 주어지면 한수가 집까지도 도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다.

첫 줄에 정수 R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가 공백으로 구분되어 주어진다.

두 번째부터 R+1번째 줄까지는 R×C 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.

첫 줄에 거리가 K인 가짓수를 출력한다.


--------입력--------
3 4 6
....
.T..
....

--------출력--------
4

*/

#include <stdio.h>

int dx[4] = { 0,0,-1,1 }; 
int dy[4] = { 1,-1,0,0 }; 
int m, n, k;
int map[5][5]; 
int visited[5][5]; 
int cnt; 
void dfs(int y, int x, int dis) {
	if (x == n-1 && y == 0 && dis==k) {
		cnt++; 
		return; 
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m )continue; 
		if (visited[ny][nx]|| map[nx][ny])continue;
		visited[ny][nx] = 1; 
		dfs(ny, nx, dis + 1); 
		visited[ny][nx] = 0; 
	}
}
int main() {
	scanf("%d %d %d", &m, &n, &k); 
	for (int i = 0; i < m; i++) {
        char s[6];
        scanf("%s", s);
		for (int j = 0; j < n; j++) {
			if (s[j] == 'T') map[i][j] = 1; 
		}
	}
	visited[m-1][0] = 1; 
	dfs(m-1, 0, 1); 
	printf("%d", cnt);
}