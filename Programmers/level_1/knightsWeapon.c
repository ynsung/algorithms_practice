#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countDivisor(int num){
    int cnt = 1;
    for(int i=1; i<=num/2; i++)
        if(num%i == 0) cnt++;
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1; i<=number; i++){
        int attack = countDivisor(i);
        if(attack>limit) answer += power;
        else answer += attack;
    }
    return answer;
}