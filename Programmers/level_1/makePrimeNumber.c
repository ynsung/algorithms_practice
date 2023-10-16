#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ifPrime(int sum){
    for(int i=2; i<= sum/2; i++){
        if(sum%i == 0) return 0;
    }
    return 1;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0, sum = 0;
    
    for(int i=0; i<nums_len-2; i++){
        for(int j=i+1; j<nums_len-1; j++){
            for(int k=j+1; k<nums_len; k++){
                sum = nums[i] + nums[j] + nums[k];
                answer += ifPrime(sum);
            }
        }
    }
    return answer;
}