// 2. 선형 스캐닝의 과정을 표시해주는 프로그램

#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key) {
	int i = 0;
	a[n] = key; // 보초법

	printf("  |");
	for (int j = 0; j < n; j++) printf(" %d", j);
	printf("\n--+");
	for (int j = 0; j < n; j++) printf("--");
	printf("-\n");

	while (1) {
		printf("  |");
		for (int j = 0; j < i; j++) printf("  ");
		printf(" *\n");

		printf(" %d|", i);
		for (int j = 0; j < n; j++) printf(" %d", a[j]);
		printf("\n");

		if (a[i] == key)  break;

		i++;
	}
	return i == n ? -1 : i;
}

int main() {
	int i, nx, ky, idx;
	int* x;
	puts("선형 검색(보초법)");
	printf("요소 개수: "); scanf_s("%d", &nx);
	x = (int*) calloc(nx + 1, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색값 : "); scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1) puts("검색에 실패했습니다.");
	else printf("%d는 x[%d]에 존재합니다.\n", ky, idx);
	free(x);
}