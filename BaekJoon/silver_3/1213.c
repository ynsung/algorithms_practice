/*
임한수와 임문빈은 서로 사랑하는 사이이다.
임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.
임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.
임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.


첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다.
정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

--------입력--------
ABACABA

--------출력--------
AABCBAA


*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[51];
    int alpha[26] = {0, };

    scanf("%s", str);
    for(int i=0; i<strlen(str); i++)
        alpha[str[i]-'A']++;
    
    int flag = 0;
    for(int i=0; i<26; i++){
        if(alpha[i]%2 == 1) flag++;
        if(flag >= 2){
            printf("I'm Sorry Hansoo");
            return 0;
        }
    }
    char c;
    for(int i=0; i<26; i++){
        if(alpha[i]%2==1) c = i+'A';
        alpha[i] /= 2;
        for(int j=0; j<alpha[i]; j++)
            printf("%c", i+'A');
    }
    if(flag >= 1)
        printf("%c", c);
    for(int i=25; i>=0; i--){
        for(int j=0; j<alpha[i]; j++)
            printf("%c", i+'A');
    }
    return 0;
}