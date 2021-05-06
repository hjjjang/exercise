/*6-2. 버블정렬*/
// Q3. (개선1 후) 배열 a가 오름차순으로 정렬을 마쳤는지 검사하는 함수 (마쳤으면 1, 아니면 0 반환)

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t=x; x=y; y=t; } while(0) // x y t -> x y x -> y y x -> y x x

int is_sorted(const int a[], int n) {
	for (int i = n-1; i > 0; i--) {
		if (a[i-1] > a[i]) return 0;
	}
	return 1;
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
	
	int sorted;
	sorted = is_sorted(x, nx);

	if (sorted) puts("배열이 정렬되어 있습니다.");
	else puts("배열이 정렬되어있지 않습니다.");

	free(x);
}
