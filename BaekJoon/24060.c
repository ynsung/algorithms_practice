#include<stdio.h>
#define size 500000
#pragma warning(disable: 4996)

int A[size];
int temp[size];
int cnt = 0;
int N, flag;
int result = -1;

void merge(int s, int e) {
	if (s >= e) return; //크기가 1인 배열까지 나누기 위한 조치

	int mid = (s + e) / 2; //divide 과정
	merge(s, mid);
	merge(mid + 1, e);

	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e) { //merge 과정.
		if (A[i] <= A[j]) temp[k++] = A[i++];
		else temp[k++] = A[j++];
	}
	while (i <= mid) temp[k++] = A[i++];
	while (j <= e) temp[k++] = A[j++];

	for (i = s; i <= e; i++) {
		A[i] = temp[i];
		cnt++;
		if (cnt == flag)
		{
			result = A[i];
			break;
		}
	}
}

int main(void)
{
	scanf("%d%d", &N, &flag);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	merge(0, N - 1);
	printf("%d", result);
	return 0;
}