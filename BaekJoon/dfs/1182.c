/*
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서
그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000)
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

--------입력--------
5 0
-7 -3 -2 5 8

--------출력--------
1
*/
#include <stdio.h>
#include <stdbool.h>

int answer = 0;
int n, sum;
int arr[21];

void dfs(bool* visited, int idx, int cnt){
    visited[idx] = true;
    cnt += arr[idx];
    if(cnt == sum) answer++;
    for(int i=idx; i<n; i++){
        if(!visited[i])
            dfs(visited, i, cnt);
    }
    visited[idx] = false;
}

int main() {
    bool visited[21];
    
    scanf("%d %d", &n, &sum);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        int cnt = 0;
        dfs(visited, i, cnt);
    }
    printf("%d", answer);
    return 0;
}