#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool IsPrime(long long int num){
    if(num == 1) return false;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0)
            return false;
    }
    return true;
}

int makeDigit(int n, int k){
    int flag, cnt = 0;
    long long int pnum = 0;
    long long int pos = 1;
    if(n%k == 0) flag = 0;
    else flag = 1;
    
    while(n >= k){
        int rem = n%k;
        n /= k;
        if(flag == 0){
            if(rem == 0) continue; // 0이 처음이거나 연속으로 나온 경우;
            else{                  // 0 다음으로 다른 숫자가 나온 경우;
                pnum = rem*pos;
                pos = 10;
                flag = 1;
            }
        }
        else{
            if(rem == 0){  // 연속된 숫자가 끝나고 0이 나온 경우
                if(IsPrime(pnum)) cnt++;
                pnum = 0;
                flag = 0;
                pos = 1;
            }
            else{          // 연속된 숫자가 계속되는 경우
                pnum += rem*pos;
                pos *= 10;
            }
        }
    }
    pnum += n*pos;
    if(IsPrime(pnum)) cnt++;
    return cnt;
}

int solution(int n, int k) {
    int answer = 0;
    if(n <= k){
        if(IsPrime(n)) answer = 1;
        else answer = 0;
    }
    else answer = makeDigit(n, k);
    
    return answer;
}