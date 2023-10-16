/*
자연수 X를 소인수분해하면, 곱해서 X가 되는 소수의 목록을 얻을 수 있다. 예를 들어, 12 = 2 × 2 × 3이다. 1은 소수가 아니다.

어떤 수 X를 소인수분해 해서 구한 소수의 목록의 길이가 소수이면, 그 수를 언더프라임 이라고 한다.

12는 목록에 포함된 소수의 개수가 3개이고, 3은 소수이니 12는 언더프라임이다.

두 정수 A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 정수 중에서 언더프라임인 것의 개수를 구해보자.
*/


#include <stdio.h>

int main(){
    int a, b, answer = 0;
    int check[100001];
    int arr[100001] = {0, };
    scanf("%d %d", &a, &b);
    for(int i=2; i<=b; i++)
        check[i] = 1;        // 소수면 1

    for(int i=2; i<=b; i++){
        if(check[i]){
            for(int j=i*2; j<=b; j+=i){
                check[j] = 0;  // 소수 아니면 0
                int num = j;
                while(num%i == 0){
                    num /= i;
                    arr[j]++;
                }
            }
        }
    }
    for(int i=a; i<=b; i++){
        if(check[arr[i]]) answer++;
    }
    printf("%d", answer);
}