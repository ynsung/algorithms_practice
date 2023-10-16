/*
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다.

조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, x2)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과

백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

한 줄에 공백으로 구분 된 여섯 정수 x1, y1, r1, x2, y2, r2가 주어진다.

각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 

만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1 출력한다.

--------입력--------

3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

--------출력--------

2
1
0

*/

#include <stdio.h>
#include <math.h>

int main() {
    int T, x1, y1, x2, y2, r1, r2;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int result;
        float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float subt = r1 > r2 ? r1 - r2 : r2 - r1;
        
        if(dist == 0 && r1 == r2) result = -1;
        else if(dist < r1 + r2 && (subt < dist)) result = 2;
        else if(dist == r1 + r2 || dist == subt) result = 1;
        else result = 0;
        
        printf("%d\n", result);
    }
    return 0;
}