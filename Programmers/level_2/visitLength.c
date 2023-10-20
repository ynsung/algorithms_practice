/*
게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

U: 위쪽으로 한 칸 가기
D: 아래쪽으로 한 칸 가기
R: 오른쪽으로 한 칸 가기
L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다.
좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.

예를 들어, "ULURRDLLU"로 명령했다면
1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.
8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.

이때, 우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다.
예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.
(8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)

단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.

예를 들어, "LULLLLLLU"로 명령했다면
1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다.
다시 9번 명령어대로 움직입니다.
이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.

dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
dirs의 길이는 500 이하의 자연수입니다.

--------입출력--------
dirs	        answer
"ULURRDLLU"	  7
"LULLLLLLU"	  7
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dot{
    bool up;
    bool right;
} dot;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    int answer = 0;
    dot line[11][11];
    int sx = 5, sy = 5;
    
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            line[i][j].up = false;
            line[i][j].right = false;
        }
    }
    while(*dirs){
        char c = *dirs++;
        if(c=='U' && sy+1<=10){
            if(!line[sx][sy].up){
                answer++;
                line[sx][sy].up = true;
            }
            sy++;
        }
        else if(c=='D' && sy-1>=0){
            if(!line[sx][sy-1].up){
                answer++;
                line[sx][sy-1].up = true;
            }
            sy--;
        }
        else if(c=='R' && sx+1<=10){
            if(!line[sx][sy].right){
                answer++;
                line[sx][sy].right = true;
            }
            sx++;
        }
        else if(c=='L' && sx-1>=0){
            if(!line[sx-1][sy].right){
                answer++;
                line[sx-1][sy].right = true;
            }
            sx--;
        }
    }
    return answer;
}