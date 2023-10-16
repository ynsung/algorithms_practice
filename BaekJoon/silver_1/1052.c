#include <stdio.h>

int main() {
    int N, K, answer = 0;
    scanf("%d %d", &N, &K);

    for(answer=0; ; answer++){
        int cnt = 0;
        int cup = N++;
        while(cup != 0){
            if(cup%2 != 0)
                cnt++;
            cup /= 2;
        }
        if(cnt <= K) break;
    }
    printf("%d",answer);
}