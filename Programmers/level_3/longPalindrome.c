/*
앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.
문자열 s가 주어질 때, s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.
예를들면, 문자열 s가 "abcdcba"이면 7을 return하고 "abacde"이면 3을 return합니다.

문자열 s의 길이 : 2,500 이하의 자연수
문자열 s는 알파벳 소문자로만 구성

--------입출력--------
s	          answer
"abcdcba"	  7
"abacde"	  3
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    
    for(int i=1; i<strlen(s); i++){
        if(s[i] == s[i-1]){
            int j = 0;
            while(i-j-1>=0 && i+j<strlen(s) && s[i-j-1]==s[i+j]) j++;
            answer = answer > 2*j ? answer : 2*j;
        }
        if(s[i-1] == s[i+1]){
            int j = 0;
            while(i-j>=0 && i+j<strlen(s) && s[i-j]==s[i+j]) j++;
            answer = answer > 2*(j-1)+1 ? answer : 2*(j-1)+1;
        }
    }
    return answer;
}