#include <stdio.h>
 
int arr[50][50];
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%1d", &arr[i][j]);
    }
 
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &num);
            if (arr[i][j] != num) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
 
    if (N < 3 || M < 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("0\n");
    }
    else {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j]) {
                    if (i < N - 2 && j < M - 2) {
                        for (int x = i; x < i + 3; x++) {
                            for (int y = j; y < j + 3; y++) {
                                arr[x][y] = !arr[x][y];
                            }
                        }
                        cnt++;
                    }
                    else {
                        if (arr[i][j]) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}