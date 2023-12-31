/*
N과 L이 주어질 때, 합이 N이면서, 길이가 적어도 L인 가장 짧은 연속된 음이 아닌 정수 리스트를 구하는 프로그램을 작성하시오.

첫째 줄에 N과 L이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이고, L은 2보다 크거나 같고, 100보다 작거나 같은 자연수이다.
만약 리스트의 길이가 100보다 작거나 같으면, 연속된 수를 첫째 줄에 공백으로 구분하여 출력한다.
만약 길이가 100보다 크거나 그러한 수열이 없을 때는 -1을 출력한다.

--------입력--------     --------출력--------
18 4                     3 4 5 6

--------입력--------     --------출력--------
18 5                     -1

*/

#include <stdio.h>

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    for(int i=L; i<=100; i++){
        int num = N/i;
        if(i%2 == 0){
            if(num+1-i/2 < 0){
                printf("-1");
                return 0;
            }
            if(N%(2*num+1) == 0){
                 for(int j=0; j<i; j++)
                     printf("%d ", num+1-i/2+j);
                 return 0;
            }
        }
        else{
            if(num-i/2 < 0){
                printf("-1");
                return 0;
            }
            else if((N-num)%(2*num) == 0){
                for(int j=0; j<i; j++)
                    printf("%d ", num-i/2+j);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}