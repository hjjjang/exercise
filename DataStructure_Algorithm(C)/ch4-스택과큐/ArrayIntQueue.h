/* int�� ť ArrayIntQueue */
#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

/*--- ť�� �����ϴ� ����ü ---*/
typedef struct {
	int max;		/* ť�� �ִ� �뷮 */
	int num;		/* ������ ��ڼ� */
	int *que;		/* ť�� ����Ű�� ������ */
} ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);

int Enque(ArrayIntQueue *q, int x);

int Deque(ArrayIntQueue *q, int *x);

int Peek(const ArrayIntQueue *q, int *x);

void Clear(ArrayIntQueue *q);

int Capacity(const ArrayIntQueue *q);

int Size(const ArrayIntQueue *q);

int IsEmpty(const ArrayIntQueue *q);

int IsFull(const ArrayIntQueue *q);

int Search(const ArrayIntQueue *q, int x);

void Print(const ArrayIntQueue *q);

void Terminate(ArrayIntQueue *q);

#endif