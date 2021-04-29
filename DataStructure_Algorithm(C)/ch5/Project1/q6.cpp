/*5-3. 하노이의 탑*/
// Q6. 하노이의 탑 문제에서 A기둥, B기둥, C기둥으로 결과를 출력하는 프로그램 구현

#include <stdio.h>

void move(int no, int x, int y) {
	if (no > 1) move(no - 1, x, 6 - x - y);
	printf("원반[%d]를(을) %c 기둥에서 %c 기둥으로 옮김\n", no, x+64, y+64);

	if (no > 1) move(no - 1, 6 - x - y, y);
}

int main() {
	int n;
	printf("하노이 탑\n원반개수: ");
	scanf_s("%d", &n);
	move(n, 1, 3);
}