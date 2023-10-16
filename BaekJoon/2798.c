#include <stdio.h>

int main() {
    int N, M, max = 0;
    int a[100];
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = a[i] + a[j] + a[k];
                if (max <= sum && sum <= M)
                    max = sum;
            }
        }
    }
    printf("%d", max);
}