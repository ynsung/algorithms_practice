/*

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 

각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

- 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
- N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
- i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.

둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

--------입력--------
3
26 40 83
49 60 57
13 89 99

--------출력--------
96

*/

#include <stdio.h>
#define MAX 1000*1000

int input[1001][4];
int dp[1001][4];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &input[i][j]);
	
	dp[1][1] = input[1][1];
	dp[1][2] = input[1][2];
	dp[1][3] = input[1][3];

	for (int i=2; i<=N; i++) {
		dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + input[i][1];
		dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + input[i][2];
		dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + input[i][3];
	}

	int min = MAX + 1;
	for (int i = 1; i <= 3; i++)
		if (dp[N][i] < min)
			min = dp[N][i];
	printf("%d", min);
	return 0;
}