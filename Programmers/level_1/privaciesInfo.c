#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int termsMonth[26];

int charToIntTerms(const char* str){
    int num;
    if(strlen(str) >= 5)
        num = 100*(str[2]-'0') + 10*(str[3]-'0') + (str[4]-'0');
    else if(strlen(str) == 4)
        num = 10*(str[2]-'0') + (str[3]-'0');
    else if(strlen(str) <= 3)
        num = str[2]-'0';
    return num;
}

void charToIntYMD(const char* date, int* yy, int* mm, int* dd){
    int pos = 1;
    for(int i=3; i>=0; i--){
        *yy += pos*(date[i]-'0');
        pos *= 10;
    }
    pos = 1;
    for(int i=6; i>=5; i--){
        *mm += pos*(date[i]-'0');
        pos *= 10;
    }
    pos = 1;
    for(int i=9; i>=8; i--){
        *dd += pos*(date[i]-'0');
        pos *= 10;
    }
}

void cntPrivacies(int* yy, int* mm, int* dd, int pm){
    *mm += pm;
    if(*mm > 12){
        if(*mm % 12 == 0){
            *yy += *mm/12-1;
            *mm = 12;
        }
        else {
            *yy += *mm/12;
            *mm -= (*mm/12)*12;
        }
    }
    *dd -= 1;
    if(*dd == 0){
        *dd = 28;
        *mm -= 1;
        if(*mm == 0){
            *mm = 12;
            *yy -= 1;
        }
    }
}

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(privacies_len*sizeof(int));
    int cnt = 0;
    int ty = 0, tm = 0, td = 0;
    
    charToIntYMD(today, &ty, &tm, &td);
    
    for(int i=0; i<terms_len; i++){
        termsMonth[terms[i][0]-'A'] = charToIntTerms(terms[i]);
    } // terms 배열에 대입

    for (int i=0; i<privacies_len; i++){
        int py = 0, pm = 0, pd = 0;
        charToIntYMD(privacies[i], &py, &pm, &pd);
        cntPrivacies(&py, &pm, &pd, termsMonth[privacies[i][11]-'A']);
        if(ty > py)
            answer[cnt++] = i+1;
        if(ty == py){
            if(tm > pm) answer[cnt++] = i+1;
            if(tm == pm && td > pd) answer[cnt++] = i+1;
        }    
    }

    return answer;
}