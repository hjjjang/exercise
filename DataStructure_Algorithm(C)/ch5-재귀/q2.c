/*5-1. ����� �⺻*/
// Q2. ����Լ��� ������� �ʰ� gcd �Լ� ����

#include <stdio.h>

int gcd(int x, int y) {
	for (int i = x; i >= 1; i--) {
		if (x % i == 0)
			if (y % i == 0) return i;
	}
}

int main() {
	int x, y;
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("ù ��° ������ �Է��ϼ���: "); scanf_s("%d", &x);
	printf("�� ��° ������ �Է��ϼ���: "); scanf_s("%d", &y);

	printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));
}
