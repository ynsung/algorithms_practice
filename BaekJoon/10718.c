#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0, pnum = 0;
    int plen = strlen(p), tlen = strlen(t);

    for (int i = 0; i < plen; i++) {
        int ten_prod = 1;
        for (int j = plen - i - 1; j > 0; j--)
            ten_prod *= 10;
        pnum += ten_prod * (p[i]-48);
    }

    for (int i = 0; i <= tlen - plen; i++) {
        int tnum = 0;
        for (int j = 0; j < plen; j++) {
            int ten_prod = 1;
            for (int k = plen - j - 1; k > 0; k--)
                ten_prod *= 10;
            tnum += ten_prod * (t[i + j]-48);
        }
        printf("%d > %d ?   ", pnum, tnum);
        if (pnum >= tnum) {
            printf("YES\n");
            answer++;
        }
        else  printf("NO\n");
    }
    return answer;
}

int main() {
    char trr[10000], prr[18];
    while (1) {
        scanf("%s %s", trr, prr);
        printf("%d\n", solution(trr, prr));
    }
}