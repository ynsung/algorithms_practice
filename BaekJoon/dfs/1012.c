#include <stdio.h>
#include <memory.h>

int arr[55][55]={0};
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};
int t,m,n,k;
int a,b;
int ans;

void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int X = x+xx[i];
        int Y = y+yy[i];

        if(X>=0 && X<n && Y>=0 && Y<m && arr[X][Y]==1){
            arr[X][Y] = 0;
            dfs(X,Y);
        }
    }

    return;
}

int main(){
    scanf("%d",&t);

    while(t--){
        ans = 0;

        scanf("%d %d %d",&m,&n,&k);

        for(int i=0;i<n;i++)
            memset(arr[i],0,m*sizeof(int));

        for(int i=0;i<k;i++){
            scanf("%d %d",&a,&b);
            arr[b][a] = 1;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(arr[i][j]==1){
                    dfs(i,j);
                    ans++;
                }

        printf("%d\n",ans);
    }

    return 0;
}


/* 여기서부터는 내가 직접 구현한 것 */
/*
#include <stdio.h>

int matrix[50][50] = {0, };
int xx[4] = {0, 0, -1, 1};
int yy[4] = {-1, 1, 0, 0};
int m, n, k, t;

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int a = x + xx[i];
        int b = y + yy[i];
        if(a >=0 && b>=0 && a<m && b<n && matrix[a][b] == 1){
            matrix[a][b] = 0;
            dfs(a, b);
        }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        int answer = 0;
        scanf("%d %d %d", &m, &n, &k);
        for(int c=0; c<k; c++){
            int x, y;
            scanf("%d %d", &x, &y);
            matrix[x][y] = 1;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    dfs(i, j);
                    answer++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                matrix[i][j] = 0;
        }
        printf("%d\n", answer);
    }
}
*/