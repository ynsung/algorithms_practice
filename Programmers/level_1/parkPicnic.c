#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dirRtn(char* str){
    if(str[0] == 'E') return 0;
    if(str[0] == 'W') return 1;
    if(str[0] == 'S') return 2;
    if(str[0] == 'N') return 3;
    return -1;
}

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    const int W = strlen(park[0]);
    const int H = park_len;
    int sx, sy;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(park[i][j] == 'S'){
                sx = i; sy = j; i = park_len;
                break;
            }
        }
    }
    
    for(int i=0; i<routes_len; i++){
        int dir = dirRtn(routes[i]);
        int n = routes[i][2] - '0';
        int cnt = 1;
        if(dir==0 && sy+n<W){
            while(park[sx][sy+cnt] != 'X'){
                if(cnt == n){
                    sy += cnt;
                    break;
                }
                cnt++;
            }
        }
        else if(dir==1 && sy-n>=0){
            while(park[sx][sy-cnt] != 'X'){
                if(cnt == n){
                    sy -= cnt;
                    break;
                }
                cnt++;
            }
        }
        else if(dir==2 && sx+n<H){
            while(park[sx+cnt][sy] != 'X'){
                if(cnt == n){
                    sx += cnt;
                    break;
                }
                cnt++;
            }
        }
        else if(dir==3 && sx-n>=0){
            while(park[sx-cnt][sy] != 'X'){
                if(cnt == n){
                    sx -= cnt;
                    break;
                }
                cnt++;
            }
        }
    }
    
    answer[0]=sx;
    answer[1]=sy;
    
    return answer;
}