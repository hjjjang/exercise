/* int형 스택 Int_DounbleStack 헤더 */
#ifndef Int_DoubleStack_h
#define Int_DoubleStack_h

enum { stackA, stackB }; //열거형으로 상수 키 정의(값은 할당하지 않은 상태)

typedef struct {
    int max; // 스택의 최대 용량
    int ptrA; // 스택 포인터A.
    int ptrB; // 스택 포인터B. 기본적으로 스택 포인터는 스택에 쌓여 있는 데이터의 개수를 나타낸다고 할 수 있는데, 이렇게 하나의 배열 안에서 두 개의 스택을 이용하는 경우, 데이터의 개수를 나타낸다고 생각하기 보단 다음 데이터를 삽입할 인덱스를 기억하는 용도라고 생각.
    int* stk; // 스택으로 사용할 배열을 가리키는 포인터
} IntDoubleStack;

// 스택 초기화
int Initialize(IntDoubleStack* s, int max);

// 스택에 데이터를 푸시
int Push(IntDoubleStack* s, int sw, int x);

// 스택에서 데이터를 팝
int Pop(IntDoubleStack* s, int sw, int* x);

// 스택에서 데이터를 피크(top에 위치하는 요소 확인)
int Peek(const IntDoubleStack* s, int sw, int* x);

// 스택 비우기
void Clear(IntDoubleStack* s, int sw);

// 스택의 최대 용량
int Capacity(const IntDoubleStack* s);

// 스택의 데이터 개수
int Size(const IntDoubleStack* s, int sw);

// 스택이 비어있나요?
int IsEmpty(const IntDoubleStack* s, int sw);

// 스택이 가득 찼나요?
int IsFull(const IntDoubleStack* s);

// 스택에서 검색
int Search(const IntDoubleStack* s, int sw, int x);

// 모든 데이터를 출력
void Print(const IntDoubleStack* s, int sw);

// 스택 종료
void Terminate(IntDoubleStack* s);


#endif /* IntDoubleStack_h */