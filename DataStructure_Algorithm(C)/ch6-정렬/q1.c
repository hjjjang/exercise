/*6-2. 버블정렬*/
// Q1. (개선 전) 버블 정렬의 각 패스에서 비교, 교환을 처음(왼쪽)부터 수행한 프로그램

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t=x; x=y; y=t; } while(0) // x y t -> x y x -> y y x -> y x x

void bubble(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n-1; j++) {
			if (a[j] > a[j+1]) swap(int, a[j], a[j+1]);
		}
	}
}

int main() {
	int nx;
	int* x;

	puts("버블 정렬");
	printf("요소 개수: "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}