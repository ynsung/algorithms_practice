#include<stdio.h>

int position(int num){
    int cnt = 0;
    while(num){
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main(){
    int a,b; scanf("%d %d", &a, &b);
    int lim = position(a);
    int cnt = 0;
    
    for(int i = 0; i < lim; i++){
        if( a % 10 == 8 ) {
            if( b - a == 0) cnt++; 	
        }
        a /= 10;
        b /= 10;
    }
    
    printf("%d", cnt);
}