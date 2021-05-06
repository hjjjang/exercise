/*3-3. 이진 검색*/
// Q5. 같은 값을 갖는 여러 개의 요소 중 가장 앞의 요소를 찾는 이진 검색

#include <stdio.h>
#include <stdlib.h>

int bin_search2(const int a[], int n, int key) {
	int pl = 0; // 검색 범위 맨 앞의 index
	int pr = n - 1; // 검색 범위 맨 뒤의 index
	int pc; // 검색 범위 중앙의 index
	int min_index;

	do {
		pc = (pl + pr) / 2; // 검색 범위 중앙의 index 업데이트
		if (a[pc] == key) {// 검색 성공
			min_index = pc;
			for (int i = pc-1; i >= 0; i--) {
				if (a[i] == key) min_index = i;
			}
			return min_index;
		}
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;

	} while (pl <= pr); // 전체 배열 탐색을 끝내기 전까지

	return -1;
}

int main() {
	int nx, ky, idx;
	puts("이진 검색");
	printf("배열 내 요소 개수: "); scanf_s("%d", &nx);
	int* x; // 배열의 첫 번째 요소에 대한 포인터
	x = (int*)calloc(nx, sizeof(int));
	
	printf("오름차순으로 입력하세요.\n");
	for (int i = 0; i < nx; i++) {
		do { 
			printf("x[%d]: ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]); // 오름차순이 아니면 다시 입력
	}

	printf("검색할 값: "); scanf_s("%d", &ky);
	idx = bin_search2(x, nx, ky);
	if (idx == -1) puts("검색에 실패했습니다.");
	else printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);

	free(x);
}