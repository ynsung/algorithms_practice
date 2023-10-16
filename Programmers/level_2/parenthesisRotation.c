/*

다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

(), [], {} 는 모두 올바른 괄호 문자열입니다.
만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다.
예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.

만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다.
예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼
회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

s의 길이는 1 이상 1,000 이하입니다.

--------입출력--------
s	         result
"[](){}"	 3
"}]()[{"	 2
"[)(]"	   0
"}}}"	     0

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[1001];
int top = -1;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    for(int i=0; i<strlen(s); i++){
        int bracket[3] = {0, };
        int flag = 0;
        for(int j=0; j<strlen(s); j++){
            int idx = (i+j)%strlen(s);
            if(s[idx] == '['){
                bracket[0]++;
                stack[++top] = 1;
            }   
            else if(s[idx] == '('){
                bracket[1]++;
                stack[++top] = 2;
            }
            else if(s[idx] == '{'){
                bracket[2]++;
                stack[++top] = 3;
            }
            else if(s[idx] == ']'){
                if(top>=0 && stack[top--] == 1) bracket[0]--;
                else{
                    flag++;
                    break;
                }
            }
            else if(s[idx] == ')'){
                if(top>=0 && stack[top--] == 2) bracket[1]--;
                else{
                    flag++;
                    break;
                }
            }
            else{
                if(top>=0 && stack[top--] == 3) bracket[2]--;
                else{
                    flag++;
                    break;
                }
            } 
        }  
        if(!flag && top<0) answer++;
    }
    return answer;
}