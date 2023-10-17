/*
8*8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다. 체스판에서 말의 위치는 다음과 같이 주어진다.
알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다.
열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다.
예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1이다.

킹은 다음과 같이 움직일 수 있다.
R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로

체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다. 
입력으로 킹이 어떻게 움직여야 하는지 주어진다.
입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.

첫째 줄에 킹의 위치, 돌의 위치, 움직이는 횟수 N이 주어진다. 둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다.
N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.
첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.

--------입력--------   --------출력--------
A1 A2 5                A1
B                      A2
L
LB
RB
LT
--------입력--------   --------출력--------
C1 B1 3                B2
L                      A1
T
LB
*/
#include <stdio.h>
#include <string.h>
#define x 0
#define y 1

int main() {
    char k[3], s[3];
    int n;
    scanf("%s", k);
    scanf("%s", s);
    scanf("%d", &n);
    
    while(n--){
        char str[3];
        scanf("%s", str);
        if(!strcmp(str,"R")){
            if(k[x]+1==s[x] && k[y]==s[y] && s[x]!='H'){
                k[x]++; s[x]++;
            }
            else if((k[x]+1!=s[x] || k[y]!=s[y]) && k[x]!='H') k[x]++;
        }
        else if(!strcmp(str,"L")){
            if(k[x]-1==s[x] && k[y]==s[y] && s[x]!='A'){
                k[x]--; s[x]--;
            }
            else if((k[x]-1!=s[x] || k[y]!=s[y]) && k[x]!='A') k[x]--;
        }
        else if(!strcmp(str,"B")){
            if(k[x]==s[x] && k[y]-1==s[y] && s[y]!='1'){
                k[y]--; s[y]--;
            }
            else if((k[x]!=s[x] || k[y]-1!=s[y]) && k[y]!='1') k[y]--;
        }
        else if(!strcmp(str,"T")){
            if(k[x]==s[x] && k[y]+1==s[y] && s[y]!='8'){
                k[y]++; s[y]++;
            }
            else if((k[x]!=s[x] || k[y]+1!=s[y]) && k[y]!='8') k[y]++;
        }
        else if(!strcmp(str,"RT")){
            if(k[x]+1==s[x] && k[y]+1==s[y] && !(s[x]=='H' || s[y]=='8')){
                k[x]++; k[y]++; s[x]++; s[y]++;
            }
            else if((k[x]+1!=s[x] || k[y]+1!=s[y]) && !(k[x]=='H' || k[y]=='8')){
                k[x]++; k[y]++;
            }
        }
        else if(!strcmp(str,"LT")){
            if(k[x]-1==s[x] && k[y]+1==s[y] && !(s[x]=='A' || s[y]=='8')){
                k[x]--; k[y]++; s[x]--; s[y]++;
            }
            else if((k[x]-1!=s[x] || k[y]+1!=s[y]) && !(k[x]=='A' || k[y]=='8')){
                k[x]--; k[y]++;
            }
        }
        else if(!strcmp(str,"RB")){
            if(k[x]+1==s[x] && k[y]-1==s[y] && !(s[x]=='H' || s[y]=='1')){
                k[x]++; k[y]--; s[x]++; s[y]--;
            }
            else if((k[x]+1!=s[x] || k[y]-1!=s[y]) && !(k[x]=='H' || k[y]=='1')){
                k[x]++; k[y]--;
            }
        }
        else if(!strcmp(str,"LB")){
            if(k[x]-1==s[x] && k[y]-1==s[y] && !(s[x]=='A' || s[y]=='1')){
                k[x]--; k[y]--; s[x]--; s[y]--;
            }
            else if((k[x]-1!=s[x] || k[y]-1!=s[y]) && !(k[x]=='A' || k[y]=='1')){
                k[x]--; k[y]--;
            }
        }
    }
    printf("%s\n%s", k, s);
    return 0;
}