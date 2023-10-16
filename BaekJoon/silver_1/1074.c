#include <stdio.h>

int main() {
    int N, r, c, answer = 0;
    scanf("%d %d %d", &N, &r, &c);
    int num = 1, j = 0;
    while(c){
        if(c == 1){
            answer++;
            break;
        }
        int sq = 1;
        while(sq*2 <= c)
            sq *= 2;
        answer += sq*sq;
        c -= sq;
    }
    while(r){
        if(r == 1){
            answer += 2;
            break;
        }
        int sq = 1;
        while(sq*2 <= r)
            sq *= 2;
        answer += sq*sq*2;
        r -= sq;
    }
    printf("%d",answer);
}