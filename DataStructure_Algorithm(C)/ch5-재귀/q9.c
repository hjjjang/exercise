/*5-4. 8퀸 문제*/
// Q8. 퀸의 배치 상황을 출력하는 8퀸 문제

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int flag_a[8]; // 각 행에 퀸을 배치했는지 체크하는 배열
int flag_b[15]; // 대각선 /에 퀸을 배치했는지 확인하는 배열
int flag_c[15]; // 대각선 \에 퀸을 배치했는지 확인하는 배열
int pos[8]; // 각 열에서 퀸의 위치

void print() {
	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) printf("%s", k == pos[i] ? "■" : "□");
		putchar('\n');
	}
	putchar('\n');
}

// i열에서 알맞은 위치에 퀸 배치
void set(int i)
{
	int j;
	IntStack jstk;
	Initialize(&jstk, 8);

Start:
	while (1) {
		j = 0;
		while (1) {
			while (j < 8) {
				if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
					pos[i] = j;
					if (i == 7)				
						print();
					else {
						flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
						i++;
						Push(&jstk, j);		 
							goto Start;
					}
				}
				j++;
			}
			if (--i == -1) return;
			Pop(&jstk, &j);					
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			j++;
		}
	}
	Terminate(&jstk);
}

int main(void)
{
	int i;

	for (i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);

	return 0;
}