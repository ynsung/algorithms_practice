#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;
    int l;
    
    /* 분할 정렬된 list 합병 */
    while(i<=mid && j<= right){
        if(list[i]<=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    
    /* 남은 값들 일괄 복사 */
    if(i>mid){
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    }
    else{
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    }
    
    /* 임시 배열에서 list[]로 복사 */
    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;  // 분할
        merge_sort(list, left, mid);     // 앞 정렬
        merge_sort(list, mid+1, right);  // 뒤 정렬
        merge(list, left, mid, right);   // 결합
    }
}

int makeMinimum(int A[], int B[], int len){
    int total = 0;
    for(int i=0; i<len; i++){
        total += A[i]*B[len-i-1];
    }
    return total;
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    
    merge_sort(A, 0, A_len-1);
    merge_sort(B, 0, B_len-1);
    answer = makeMinimum(A, B, A_len);
    
    return answer;
}