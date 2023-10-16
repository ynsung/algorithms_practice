#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0, scnt = 0;
    
    for(int i=1; i<=n; i++){
        if(i == section[scnt]){
            i += m-1;
            while(i>=section[scnt]) scnt++;
            answer++;
        }
    }
    return answer;
}