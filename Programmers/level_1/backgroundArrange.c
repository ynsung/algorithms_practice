#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int checkFile(char c){
    if(c == '#') return 1;
    else return 0;
}

void swap(int* a, int* b){
    if(*a > *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4*sizeof(int));
    int width = strlen(wallpaper[0]);
    int height = wallpaper_len;
    int lux, luy, rdx, rdy, firstFlag = 1; 
    
    for(int r=0; r<height; r++){
        for(int c=0; c<width; c++){
            if(checkFile(wallpaper[r][c])){
                if(firstFlag){
                    lux = rdx = r; 
                    luy = rdy = c;
                    firstFlag=0;
                }
                else {
                    swap(&lux, &r); swap(&luy, &c);
                    swap(&r, &rdx); swap(&c, &rdy);
                }
            }
        }
    }
    
    answer[0] = lux;
    answer[1] = luy;
    answer[2] = rdx + 1;
    answer[3] = rdy + 1;
    
    return answer;
}