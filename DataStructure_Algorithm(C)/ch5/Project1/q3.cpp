/*5-2. ��� �˰��� �м�*/
// Q3. �迭 a�� ��� ����� �ִ� ������� ���ϴ� �Լ� �ۼ� (*)

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int gcd_array(const int a[], int n){
	if (n == 1) return a[0];
	else if (n == 2) return gcd(a[0], a[1]);
	else return gcd(a[0], gcd_array(&a[1], n - 1)); //&a[1]: �� ��° ����� �ּڰ� => �� ��°���� ���������� // n-1: ����� ���� �ϳ� �پ��
}

int main() {
	int nx;
	int* x; // �迭�� ù ��° ��ҿ� ���� ������
	printf("����� ������ �Է��ϼ���: "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("�ִ������� %d�Դϴ�.\n", gcd_array(x, nx));

	free(x);
}
