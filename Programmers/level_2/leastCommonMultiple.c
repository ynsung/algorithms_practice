#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int matrix[100] = {0, };

void makeMatrix(int n){
    int i = 2;
    while(n > 1){
        int cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(matrix[i] < cnt) matrix[i] = cnt;
        i++;
    }
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t len) {
    int answer = 1;
    for(int i=0; i<len; i++)
       makeMatrix(arr[i]);

    for(int i=2; i<98; i++){
        while(matrix[i] > 0){
            answer *= i;
            matrix[i] -= 1;
        }
    }
    return answer;
}