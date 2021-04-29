/*5-2. 재귀 알고리즘 분석*/
// Q3. 배열 a의 모든 요소의 최대 공약수를 구하는 함수 작성 (*)

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int gcd_array(const int a[], int n){
	if (n == 1) return a[0];
	else if (n == 2) return gcd(a[0], a[1]);
	else return gcd(a[0], gcd_array(&a[1], n - 1)); //&a[1]: 두 번째 요소의 주솟값 => 두 번째부터 마지막까지 // n-1: 요소의 개수 하나 줄어듦
}

int main() {
	int nx;
	int* x; // 배열의 첫 번째 요소에 대한 포인터
	printf("요소의 개수를 입력하세요: "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("최대공약수는 %d입니다.\n", gcd_array(x, nx));

	free(x);
}
