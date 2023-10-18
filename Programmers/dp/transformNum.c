#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int x, int y, int n) {
    int step[1000001];
    step[x] = 0;
    for (int i = x + 1; i <= y; i++)
        step[i] = 1000000;
    for (int i = x; i < y; i++) {
        int count = step[i] + 1;
        int interm = i * 2;
        if (interm <= y && step[interm] > count) {
            step[interm] = count;
        }
        interm = i * 3;
        if (interm <= y && step[interm] > count) {
            step[interm] = count;
        }
        interm = i + n;
        if (interm <= y && step[interm] > count) {
            step[interm] = count;
        }            
    }
    if (step[y] == 1000000)
        return -1;
    return step[y];
}

/*
int solution(int x, int y, int n) {
    int DP[1000001] = { 0 };
    DP[x] = 1;
    for(int i = x; i < 1000000; i++) {
        if(!DP[i]) continue;
        if(i * 3 <= 1000000 && (!DP[i * 3] || DP[i] + 1 < DP[i * 3])) DP[i * 3] = DP[i] + 1;
        if(i * 2 <= 1000000 && (!DP[i * 2] || DP[i] + 1 < DP[i * 2])) DP[i * 2] = DP[i] + 1;
        if(i + n <= 1000000 && (!DP[i + n] || DP[i] + 1 < DP[i + n])) DP[i + n] = DP[i] + 1;
    }
    return DP[y] -1;
}
*/