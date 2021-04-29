/*5-1. 재귀의 기본*/
// Q1. 재귀함수를 사용하지 않고 factorial 함수 구현

#include <stdio.h>

int factorial(int n) {
	int num = 1;
	if (n == 0) return 1;
	for (int i = 1; i <= n; i++) {
		num *= i;
	}
	return num;
}

int main() {
	int x;
	printf("정수를 입력하세요: "); scanf_s("%d", &x);
	printf("%d의 순차곱셋 값은 %d입니다.\n", x, factorial(x));
}
