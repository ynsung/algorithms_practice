/*
어떤 수열의 연속 부분 수열에 같은 길이의 펄스 수열을 각 원소끼리 곱하여 연속 펄스 부분 수열을 만들려 합니다.
펄스 수열이란 [1, -1, 1, -1 …] 또는 [-1, 1, -1, 1 …] 과 같이 1 또는 -1로 시작하면서 1과 -1이 번갈아 나오는 수열입니다.

예를 들어 수열 [2, 3, -6, 1, 3, -1, 2, 4]의 연속 부분 수열 [3, -6, 1]에 펄스 수열 [1, -1, 1]을 곱하면 연속 펄스 부분수열은 [3, 6, 1]이 됩니다.
또 다른 예시로 연속 부분 수열 [3, -1, 2, 4]에 펄스 수열 [-1, 1, -1, 1]을 곱하면 연속 펄스 부분수열은 [-3, -1, -2, 4]이 됩니다.
정수 수열 sequence가 매개변수로 주어질 때, 연속 펄스 부분 수열의 합 중 가장 큰 것을 return 하도록 solution 함수를 완성해주세요.

1 ≤ sequence의 길이 ≤ 500,000
-100,000 ≤ sequence의 원소 ≤ 100,000
sequence의 원소는 정수입니다.

--------입출력--------
sequence	                    result
[2, 3, -6, 1, 3, -1, 2, 4]	  10
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
long long solution(int sequence[], size_t sequence_len) {
    long long answer = 0;
    int* a = (int*)malloc(sizeof(int)*(sequence_len+1));
    int* b = (int*)malloc(sizeof(int)*(sequence_len+1));
    int pulse[2] = {-1, 1};
    long long int ac[50000], bc[50000];
    if(sequence_len < 2){
        if(sequence[0] >= 0) return sequence[0];
        else return sequence[0]*-1;
    }
    for(int i=0; i<sequence_len; i++){
        a[i] = sequence[i] * pulse[i%2];
        b[i] = sequence[i] * pulse[(i+1)%2];
    }
    ac[0] = a[0];
    bc[0] = b[0];
    for(int i=1; i<sequence_len; i++){
        long long int amax = 0 > ac[i-1] ? 0 : ac[i-1];
        long long int bmax = 0 > bc[i-1] ? 0 : bc[i-1];
        ac[i] = amax + a[i];
        bc[i] = bmax + b[i];
        answer = ac[i] > answer ? ac[i] : answer;
        answer = bc[i] > answer ? bc[i] : answer;
    }
    free(a);
    free(b);
    return answer;
}