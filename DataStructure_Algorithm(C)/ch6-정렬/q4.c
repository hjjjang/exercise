/*6-2. 버블정렬*/
// Q4. (개선1 후) 비교, 교환 과정을 자세히 출력하는 버블 정렬 프로그램

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t=x; x=y; y=t; } while(0) // x y t -> x y x -> y y x -> y x x

void bubble(int a[], int n) {
	int compare = 0;
	int exchange = 0;
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		printf("패스%d:\n", i);
		for (int j = n - 1; j > i; j--) {
			for (int k = 0; k < n; k++) {
				printf("%d", a[k]);
				k != j - 1 ? (k == n - 1 ? printf("\n") : printf(" ")) : (a[j - 1] > a[j] ? printf("+") : printf("-"));
			}
			compare++;
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
				exchange++;
			}
		}
		for (int l = 0; l < n; l++) printf("%d ", a[l]);
		printf("\n");

		if (exchg == 0) break;
	}
	printf("총 비교를 %d회 했습니다.\n", compare);
	printf("총 교환을 %d회 했습니다.\n", exchange);
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

	free(x);
}
