/*
강토는 Day Of Mourning의 기타리스트로, 다가오는 공연을 준비하고 있다.
어느 날 강토의 집에 도둑이 들어서 기타를 모두 도둑맞고 말았다. 기타를 사야 한다.
강토는 공연 때 연주할 노래의 목록을 뽑아 놓았다. 하지만, 하나의 기타로 모든 곡을 연주할 수는 없다.
어떤 기타는 어떤 곡을 연주할 때, 이상한 소리가 나기 때문이다. 항상 완벽을 추구하는 강토는 이런 일을 용납하지 않는다.

최대한 많은 곡을 제대로 연주하려고 할 때, 필요한 기타의 최소 개수를 구하는 프로그램을 작성하시오.

예를 들어, GIBSON으로 1, 2, 3번 곡을 제대로 연주할 수 있고, FENDER로 1, 2, 5번 곡을 제대로 연주할 수 있고,
EPIPHONE으로 4, 5번 곡을 제대로 연주할 수 있고, ESP로 1번곡을 제대로 연주할 수 있다면,
세준이는 EPIPHONE과 GIBSON을 사면 최소의 개수로 모든 곡을 연주할 수 있다. 

첫째 줄에 기타의 개수 N과 곡의 개수 M이 주어진다. N은 10보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에 기타의 이름과 기타가 연주할 수 있는 곡의 정보가 1번 곡부터 차례대로 주어진다. Y는 연주할 수 있는 것이고, N은 없는 것이다.
기타의 이름은 알파벳 대문자로만 이루어져 있고, 길이는 2 이상, 50 이하이다. 두 기타의 이름이 같은 경우는 없다.
첫째 줄에 필요한 기타의 개수를 출력한다. 만약 연주할 수 있는 곡이 없으면 -1을 출력한다.

--------입력--------
4 5
GIBSON YYYNN
FENDER YYNNY
EPIPHONE NNNYY
ESP YNNNN

--------출력--------
2
*/
#include <stdio.h>
#include <stdbool.h>

char song[10][51];
int msong[51] = {0, };
int ms = 0, n, m, min = 51;

void dfs(bool* visited, int i, char* str, int cnt, int guitar){
    visited[i] = true;

    for(int j=i+1; j<n; j++){
        if(!visited[j] && cnt<ms){
            char arr[51];
            int ant = 0;
            for(int k=0; k<m; k++){
                if(str[k] == 'Y' || song[j][k] == 'Y') arr[k] = 'Y';
                else arr[k] = 'N';
            }   
            for(int k=0; k<m; k++)
                if(arr[k] == 'Y') ant++;
            dfs(visited, j, arr, ant, guitar+1);
        }
    }
    
    if(cnt == ms)
        min = min < guitar ? min : guitar;
    visited[i] = false;
}


int main() {
    bool visited[10];
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        char str[51];
        int cnt = 0;
        scanf("%s %s", str, song[i]);
        for(int j=0; j<m; j++){
            if(song[i][j] == 'Y'){
                msong[j] = 1;
                cnt++;
            }
        }
        if(cnt == m){
            printf("1");
            return 0;
        }
    }
    for(int j=0; j<m; j++)
        if(msong[j] == 1) ms++;
    if(ms == 0){
        printf("-1");
        return 0;
    }
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=0; i<n; i++){
        int cnt = 0, guitar = 1;
        for(int j=0; j<m; j++)
            if(song[i][j] == 'Y') cnt++;
        dfs(visited, i, song[i], cnt, guitar);   
    }
    printf("%d", min);
    return 0;
}