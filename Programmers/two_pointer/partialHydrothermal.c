#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
int* solution(int sequence[], size_t sequence_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    int left = sequence_len-1;
    int right = sequence_len-1;
    int sum = sequence[right];
    
    while(left >= 0){
        if(sum < k){
            left--;
            sum += sequence[left];
        }
        else if(sum > k){
            sum -= sequence[right];
            right--;
        }
        else{
            while(sequence[left-1] == sequence[right]){
                left--;
                right--;
            }
            answer[0] = left;
            answer[1] = right;
            return answer;
        }
    }
}