/*
볼록 다각형이 있고, 여기서 3개의 연속된 점을 선택해서 삼각형을 만든다. 그 다음, 만든 삼각형을 다각형에서 제외한다.
원래 다각형이 N개의 점이 있었다면, 이제 N-1개의 점으로 구성된 볼록 다각형이 된다.
위의 과정은 남은 다각형이 삼각형이 될 때까지 반복한다.

볼록 다각형의 점이 시계 방향순으로 주어진다. 마지막에 남은 삼각형은 여러 가지가 있을 수 있다.
이때, 가능한 넓이의 최댓값을 구하는 프로그램을 작성하시오.

첫째 줄에 볼록 다각형 점의 수 N (3 ≤ N ≤ 35)이 주어진다.
둘째 줄부터 N개의 줄에는 볼록 다각형을 이루고 있는 점이 시계 방향 순서로 주어진다.
좌표는 10,000보다 작거나 같은 자연수이다.
첫째 줄에 문제의 정답을 출력한다. 절대/상대 오차는 10^-9까지 허용한다.

--------입력--------
4
1 1
1 2
3 3
2 1

--------출력--------
1.5

*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double max = 0;

void triangle(double* x, double* y, double* z){
    double a= sqrt((y[0]-x[0])*(y[0]-x[0])+(y[1]-x[1])*(y[1]-x[1]));
    double b= sqrt((z[0]-y[0])*(z[0]-y[0])+(z[1]-y[1])*(z[1]-y[1]));
    double c= sqrt((z[0]-x[0])*(z[0]-x[0])+(z[1]-x[1])*(z[1]-x[1]));
    double s = (a+b+c)/2;
    double result = sqrt(s*(s-a)*(s-b)*(s-c));
    max = result > max ? result : max;
    return;
}

int main() {
    int n = 0;
    double dot[35][2];
    
    scanf("%d", &n);
    int depth = n;
    for(int i=0; i<n; i++)
        scanf("%lf %lf", &dot[i][0], &dot[i][1]);

    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++)
                triangle(dot[i], dot[j], dot[k]);
        }
    }
    printf("%.9f", max);
    return 0;
}