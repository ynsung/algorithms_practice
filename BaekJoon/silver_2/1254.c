/*
동호와 규완이는 212호에서 문자열에 대해 공부하고 있다. 규완이는 팰린드롬을 엄청나게 좋아한다.
팰린드롬이란 앞에서부터 읽으나 뒤에서부터 읽으나 같게 읽히는 문자열을 말한다.

동호는 규완이를 위한 깜짝 선물을 준비했다.
동호는 규완이가 적어놓고 간 문자열 S에 0개 이상의 문자를 문자열 뒤에 추가해서 팰린드롬을 만들려고 한다.
동호는 가능하면 가장 짧은 문자열을 만들려고 한다.

동호가 만들 수 있는 가장 짧은 팰린드롬의 길이를 출력하는 프로그램을 작성하시오.

첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 최대 50이다.
첫째 줄에 동호가 만들 수 있는 가장 짧은 팰린드롬의 길이를 출력한다.

--------입력--------
abab

--------출력--------
5
*/
#include <stdio.h>
#include <string.h>

int main() {
    int minnim = 101, minim = 101;
    char s[51];
    scanf("%s", s);
    
    if(strlen(s) < 2){
        printf("1");
        return 0;
    }
    
    for(int i=strlen(s)/2; i<strlen(s); i++){
        if(strlen(s)%2 == 0){
            int k = 0;
            while(i+k < strlen(s)){
                if(s[i-k-1] == s[i+k]) k++;
                else break;
            }
            if(i+k == strlen(s)){
                minnim = 2*i;
                break;
            }
        }
        else{
            int k = 0;
            while(i+k < strlen(s)){
                if(s[i-k] == s[i+k+1]) k++;
                else break;
            }
            if(i+k+1 == strlen(s)){
                minnim = 2*(i+1);
                break;
            }
        }
    }
    
    for(int i=strlen(s)/2; i<strlen(s); i++){
        int j=0;
        while(i+j<strlen(s)){
            if(s[i+j] == s[i-j]) j++;
            else break;
        }
        if(i+j == strlen(s)){
            minim = 2*i+1;
            break;
        }
    }
    
    minim = minnim > minim ? minim : minnim;
    printf("%d", minim);
    
    return 0;
}