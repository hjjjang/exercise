// 4. 찾은 데이터가 맨 앞의 요소로부터 상대적으로 몇 번째 위치에 있는지에 대한 인덱스 값을 반환하는 search함수

int Search2(const IntQueue* q, int x) {
	for (int i = 0; i < q->num; i++) {
		if (q->que[(i + q->front) % q->max] == x)
			return i;
	}
	return -1;
}