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

void recur3(int n) {
	int sw = 0;

	IntStack nstk, sstk;
	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (n > 0) {
			Push(&nstk, n); //printf("Push(%s,n)", nstk);
			Push(&sstk, sw); //printf("Push(%s,sw)", sstk);

			if (sw == 0) n = n - 1;
			else if (sw == 1) {
				n = n - 1;
				sw = 0;
			}
			continue;
		}
		do {
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2) {
				printf("%d\n", n);
				if (IsEmpty(&nstk)) return;
			}
		} while (sw == 2);
	}
	Terminate(&nstk);
	Terminate(&sstk);
}

int main(void) {
	int x;
	printf("정수를 입력하세요: "); scanf_s("%d", &x);
	recur3(x);
	return 0;
}
