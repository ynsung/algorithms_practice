/*
지민이는 세계에서 가장 유명한 사람이 누구인지 궁금해졌다.
가장 유명한 사람을 구하는 방법은 각 사람의 2-친구를 구하면 된다.
어떤 사람 A가 또다른 사람 B의 2-친구가 되기 위해선, 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재해야 된다.
여기서 가장 유명한 사람은 2-친구의 수가 가장 많은 사람이다. 가장 유명한 사람의 2-친구의 수를 출력하는 프로그램을 작성하시오.

A와 B가 친구면, B와 A도 친구이고, A와 A는 친구가 아니다.

첫째 줄에 사람의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에 각 사람이 친구이면 Y, 아니면 N이 주어진다.
첫째 줄에 가장 유명한 사람의 2-친구의 수를 출력한다.

--------입력--------         --------출력--------
3                            2
NYY
YNY
YYN
--------입력--------         --------출력--------
5                            4
NYNNN
YNYNN
NYNYN
NNYNY
NNNYN
*/
#include <stdio.h>

char map[51][51];
int f[51][51] = {0, };

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", map[i]);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'Y'){
                f[i][j]++;
                for(int k=0; k<n; k++){
                    if(map[j][k] == 'Y' && k!=i){
                        f[i][k]++;
                    }
                }
            }
        }
    }
    int max = 0;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++)
            if(f[i][j] > 0) cnt++;
        if(cnt > max) max = cnt;
    }
    printf("%d", max);
    return 0;
}
