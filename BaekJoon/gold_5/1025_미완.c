#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int answer = -1;

void checkSquare(int num){
    float n = sqrt(num)*1000;
    int a = n/1;
    if(a%1000 == 0 && num > answer)
        answer = num;
}

int main() {
    int N, M;
    int matrix[9][9] = {0, 0};
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        int num;
        scanf("%d", &num);
        for(int j=M-1; j>=0; j--){
            matrix[i][j] = num%10;
            num /= 10;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int edx = matrix[i][j];
            if (edx == 0 || edx == 1 || edx == 4 || edx == 5 || edx == 6 || edx == 9){
                for(int k=0; k<N; k++){
                    for(int l=0; l<M; l++){
                        int sdx = matrix[k][l];
                        if(sdx == 0){
                            checkSquare(edx);
                            continue;
                        }
                        else if(i==k && j==l) checkSquare(edx);
                        else{

                        }
                    
                }
            }
            else continue;
        }
    }
    printf("%d",answer);
}