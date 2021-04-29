/*5-2. 재귀 알고리즘 분석*/
// Q5. 다음의 recur3 함수를 비재귀적으로 변경
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
				printf("n - 1해서 n값: %d, sw값: %d\n", n, sw);
			}
			else if (sw == 1) {
				n = n - 2;
				printf("n - 2해서 n값: %d\n", n);
				sw = 0;
			}
			continue;
		}
		do {
			printf("\ndo문 실행\n");
			printf("Pop 전 n[%d]\n", n);
			Pop(&nstk, &n);
			printf("Pop 후 n[%d]\n", n);
			printf("Pop 전 sw[%d]\n", sw);
			Pop(&sstk, &sw);
			printf("Pop 후 sw[%d]\n", sw);
			sw++;
			printf("sw++해서 sw값: %d\n", sw);

			if (sw == 2) {
				printf("do문 안의 if문 실행\n");
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

	printf("정수를 입력하세요. : ");
	scanf_s("%d", &x);

	recur3(x);

	return 0;
}