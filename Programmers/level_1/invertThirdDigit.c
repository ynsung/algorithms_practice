#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countPosition(int n){
    int cnt = 0;
    while(n/3 != 0){
        n /= 3;
        cnt++;
    }
    return cnt;
}

int invertThirdDigit(int n, int pos){
    int threeSquare = 1, thirdDigit = 0;
    
    for(int i=0; i<pos; i++)
        threeSquare *= 3;
    
    for(int i=0; i<=pos; i++){
        thirdDigit += (n%3)*threeSquare;
        n /= 3;
        threeSquare /= 3;
    }
    return thirdDigit;
}

int solution(int n) {
    int answer = 0;
    int pos = countPosition(n);
    answer = invertThirdDigit(n, pos);
    return answer;
}