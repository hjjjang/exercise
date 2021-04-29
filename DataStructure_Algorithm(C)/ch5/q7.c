/*5-3. 하노이의 탑*/
// Q7. 하노이의 탑 문제에서 move함수를 비재귀적으로 수정

#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y) {
	int sw = 0;
	IntStack xstk, ystk, sstk;		/* 스택 */
	
	Initialize(&xstk, 100);
	Initialize(&ystk, 100);
	Initialize(&sstk, 100);
	
	while (1) {
		if (sw == 0 && no > 1) {
			Push(&xstk, x);				/* x 값을 푸시 */
			Push(&ystk, y);				/* y 값을 푸시 */
			Push(&sstk, sw);			/* sw 값을 푸시 */
			no = no - 1;
			y = 6 - x - y;
			continue;
		}
	
		printf("원반[%d]를 %d 기둥에서 %d 기둥으로 이동\n", no, x, y);
	
		if (sw == 1 && no > 1) {
			Push(&xstk, x);				/* x 값을 푸시 */
			Push(&ystk, y);				/* y 값을 푸시 */
			Push(&sstk, sw);			/* sw 값을 푸시 */
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&xstk))			/* 스택이 비어있는 상태라면 */
				return;
			Pop(&xstk, &x);				/* x를 팝 */
			Pop(&ystk, &y);				/* y를 팝 */
			Pop(&sstk, &sw);			/* sw를 팝 */
			sw++;
			no++;
		} while (sw == 2);
	}
	
	Terminate(&xstk);
	Terminate(&ystk);
	Terminate(&sstk);
}

int main() {
	int n;
	printf("하노이 탑\n원반개수: ");
	scanf_s("%d", &n);
	move(n, 1, 3);
}