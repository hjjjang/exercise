/*5-3. �ϳ����� ž*/
// Q7. �ϳ����� ž �������� move�Լ��� ����������� ����

#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y) {
	int sw = 0;
	IntStack xstk, ystk, sstk;		/* ���� */
	
	Initialize(&xstk, 100);
	Initialize(&ystk, 100);
	Initialize(&sstk, 100);
	
	while (1) {
		if (sw == 0 && no > 1) {
			Push(&xstk, x);				/* x ���� Ǫ�� */
			Push(&ystk, y);				/* y ���� Ǫ�� */
			Push(&sstk, sw);			/* sw ���� Ǫ�� */
			no = no - 1;
			y = 6 - x - y;
			continue;
		}
	
		printf("����[%d]�� %d ��տ��� %d ������� �̵�\n", no, x, y);
	
		if (sw == 1 && no > 1) {
			Push(&xstk, x);				/* x ���� Ǫ�� */
			Push(&ystk, y);				/* y ���� Ǫ�� */
			Push(&sstk, sw);			/* sw ���� Ǫ�� */
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&xstk))			/* ������ ����ִ� ���¶�� */
				return;
			Pop(&xstk, &x);				/* x�� �� */
			Pop(&ystk, &y);				/* y�� �� */
			Pop(&sstk, &sw);			/* sw�� �� */
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
	printf("�ϳ��� ž\n���ݰ���: ");
	scanf_s("%d", &n);
	move(n, 1, 3);
}