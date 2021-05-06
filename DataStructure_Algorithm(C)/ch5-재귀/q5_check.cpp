/*5-2. ��� �˰��� �м�*/
// Q5. ������ recur3 �Լ��� ����������� ����
/*
void recur3(int n) {
	if (n > 0) {
		recur3(n - 1);
		recur3(n - 2);
		printf("%d\n", n);
	}
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (n > 0) {
			Push(&nstk, n);
			printf("Push n(%d)\n", n);
			Push(&sstk, sw);
			printf("Push sw(%d)\n", sw);

			if (sw == 0) {
				n = n - 1;
				printf("n - 1�ؼ� n��: %d, sw��: %d\n", n, sw);
			}
			else if (sw == 1) {
				n = n - 2;
				printf("n - 2�ؼ� n��: %d\n", n);
				sw = 0;
			}
			continue;
		}
		do {
			printf("\ndo�� ����\n");
			printf("Pop �� n[%d]\n", n);
			Pop(&nstk, &n);
			printf("Pop �� n[%d]\n", n);
			printf("Pop �� sw[%d]\n", sw);
			Pop(&sstk, &sw);
			printf("Pop �� sw[%d]\n", sw);
			sw++;
			printf("sw++�ؼ� sw��: %d\n", sw);

			if (sw == 2) {
				printf("do�� ���� if�� ����\n");
				printf("%d\n", n);
				if (IsEmpty(&nstk))
					return;
			}
		} while (sw == 2);
	}

	Terminate(&nstk);
	Terminate(&sstk);
}

int main(void)
{
	int x;

	printf("������ �Է��ϼ���. : ");
	scanf_s("%d", &x);

	recur3(x);

	return 0;
}