#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mbti[8] = {0, }; // RT CF JM AN

void countScore(char srvStandard, int score){
    switch(srvStandard){
        case 'R':
            if(score < 4) mbti[0] += (score-4)*(-1);
            else mbti[1] += (score-4);
            break;
        case 'T' :
            if(score < 4) mbti[1] += (score-4)*(-1);
            else mbti[0] += score-4;
            break;
        case 'C' :
            if(score < 4) mbti[2] += (score-4)*(-1);
            else mbti[3] += score-4;
            break;
        case 'F' :
            if(score < 4) mbti[3] += (score-4)*(-1);
            else mbti[2] += score-4;
            break;
        case 'J' :
            if(score < 4) mbti[4] += (score-4)*(-1);
            else mbti[5] += score-4;
            break;
        case 'M' :
            if(score < 4) mbti[5] += (score-4)*(-1);
            else mbti[4] += score-4;
            break;
        case 'A' :
            if(score < 4) mbti[6] += (score-4)*(-1);
            else mbti[7] += score-4;
            break;
        default :
            if(score < 4) mbti[7] += (score-4)*(-1);
            else mbti[6] += score-4;
    }
}

void setMBTI(char* str){
    if(mbti[0] >= mbti[1]) str[0] = 'R';
    else str[0] = 'T';
    
    if(mbti[2] >= mbti[3]) str[1] = 'C';
    else str[1] = 'F';
    
    if(mbti[4] >= mbti[5]) str[2] = 'J';
    else str[2] = 'M';
    
    if(mbti[6] >= mbti[7]) str[3] = 'A';
    else str[3] = 'N';
    
    str[4] = '\0';
}

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(5*sizeof(char));
    char str[4];
    
    for(int i=0; i<survey_len; i++){
        countScore(survey[i][0], choices[i]);
    }
    setMBTI(answer);
    return answer;
}