#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int arr[1000000];
    int j=0;
    
    for(int i=0; i<ingredient_len; i++){
        arr[j] = ingredient[i];
        if(arr[j] == 1){
            if(arr[j-3] == 1 && arr[j-2] == 2 && arr[j-1] == 3){
            j -= 3;
            answer++;
            }
            else j++;
        }
        else j++;
    }
    return answer;
}