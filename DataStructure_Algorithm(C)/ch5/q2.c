/*5-1. 재귀의 기본*/
// Q2. 재귀함수를 사용하지 않고 gcd 함수 구현

#include <stdio.h>

int gcd(int x, int y) {
	for (int i = x; i >= 1; i--) {
		if (x % i == 0)
			if (y % i == 0) return i;
	}
}

int main() {
	int x, y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("첫 번째 정수를 입력하세요: "); scanf_s("%d", &x);
	printf("두 번째 정수를 입력하세요: "); scanf_s("%d", &y);

	printf("최대공약수는 %d입니다.\n", gcd(x, y));
}
