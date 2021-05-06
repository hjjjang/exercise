// 1.선형 검색 w/ 보초법을 for문을 사용하여 구현

#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key) {
	a[n] = key;
	for (int i = 0; i < n; i++) {
		if (a[i] == key) return i;
	}
	return -1;
}