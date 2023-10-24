/*
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.

--------입출력--------
prices	          return
[1, 2, 3, 2, 3]	  [4, 3, 1, 1, 0]
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _stack{
    int idx;
    int val;
}stack;

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*prices_len);
    int top = 0, pnt = 0;
    stack s[10001];
    
    s[++top].val = prices[0];
    s[top].idx = 0;
    for(int i=1; i<prices_len; i++){
        while(top>0 && s[top].val>prices[i]){
            answer[s[top].idx] = i - s[top].idx;
            top--;
        }   
        s[++top].val = prices[i];
        s[top].idx = i;
    }
    while(top){
        answer[s[top].idx] = prices_len - s[top].idx - 1;
        top--;
    }
    return answer;
}