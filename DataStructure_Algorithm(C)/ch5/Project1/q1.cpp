/*5-1. ����� �⺻*/
// Q1. ����Լ��� ������� �ʰ� factorial �Լ� ����

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
	printf("������ �Է��ϼ���: "); scanf_s("%d", &x);
	printf("%d�� �������� ���� %d�Դϴ�.\n", x, factorial(x));
}
