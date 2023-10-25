/*
만약 어떤 단어A를 숌스럽게 바꿔서 또다른 단어 B로 만든다면, 그 단어는 비슷한 단어라고 한다.

어떤 단어를 숌스럽게 바꾼다는 말은 단어 A에 등장하는 모든 알파벳을 다른 알파벳으로 바꾼다는 소리다.
그리고, 단어에 등장하는 알파벳의 순서는 바뀌지 않는다.
두 개의 다른 알파벳을 하나의 알파벳으로 바꿀 수 없고, 임의의 알파벳을 자기 자신으로 바꾸는 것은 가능하다.

예를 들어, 단어 abca와 zbxz는 비슷하다. 그 이유는 a를 z로 바꾸고, b는 그대로 b, c를 x로 바꾸면, abca가 zbxz가된다.
단어가 여러 개 주어졌을 때, 몇 개의 쌍이 비슷한지 구하는 프로그램을 작성하시오.

첫째 줄에 단어의 개수 N이 주어진다. 둘째 줄부터 N개의 줄에 한 줄에 하나씩 단어가 주어진다.
단어의 길이는 최대 50이고, N은 100보다 작거나 같은 자연수이다. 모든 단어의 길이는 같고, 중복되지 않는다.
또, 알파벳 소문자로만 이루어져 있다.
첫째 줄에 총 몇 개의 쌍이 비슷한지 출력한다.

--------입력-------- 
5
aa
ab
bb
cc
cd

--------출력--------
4
*/
#include <stdio.h>
#include <string.h>

int main() {
    int n, alpha[26], answer = 0;
    char s[100][51], r[100][51] = {0, };
    
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s", s[i]);

    int len = strlen(s[0]);  
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int l=0; l<26; l++)
            alpha[l] = 0;
        for(int j=0; j<len; j++){
            if(alpha[s[i][j]-'a'] > 0){
                r[i][j] = alpha[s[i][j]-'a'];
            }
            else{
                r[i][j] = cnt;
                alpha[s[i][j]-'a'] = cnt++;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            if(!strcmp(r[i], r[j])) answer++;
    }
    printf("%d", answer);
    return 0;
}