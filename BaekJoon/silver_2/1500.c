/*
세준이는 정수 S와 K가 주어졌을 때, 합이 S인 K개의 양의 정수를 찾으려고 한다.
만약 여러개일 경우 그 곱을 가능한 최대로 하려고 한다.
가능한 최대의 곱을 출력한다.
만약 S=10, K=3이면, 3,3,4는 곱이 36으로 최대이다.

첫째 줄에 두 수 S와 K가 주어진다. K는 20보다 작거나 같고, S는 100보다 작거나 같으며 K보다 크거나 같다.
첫째 줄에 정답을 출력한다. 답은 9223372036854775807보다 작다.

--------입력--------
10 3

--------출력--------
36
*/
#include <stdio.h>

int main() {
    int s, k, arr[20];
    scanf("%d %d", &s, &k);
    long long int answer = 1;
    int num = s/k;
    for(int i=0; i<k; i++)
        arr[i] = num;
    if(s%k > 0){
        num = s - s/k*k;
        for(int i=0; i<num; i++)
            arr[i]++; 
    }
    for(int i=0; i<k; i++)
        answer *= arr[i];
    printf("%lld", answer);
    return 0;
}