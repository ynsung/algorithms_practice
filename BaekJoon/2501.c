#include<stdio.h>
#pragma warning(disable:4996)

int main() {
    int num, order, p = 0, q = 0;
    scanf("%d %d", &num, &order);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            q = i; p++;
            if (p == order) {
                printf("%d", q);
                return 0;
            }
        }
    }
    printf("0");
}