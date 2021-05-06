/* int�� ���� Int_DounbleStack ��� */
#ifndef Int_DoubleStack_h
#define Int_DoubleStack_h

enum { stackA, stackB }; //���������� ��� Ű ����(���� �Ҵ����� ���� ����)

typedef struct {
    int max; // ������ �ִ� �뷮
    int ptrA; // ���� ������A.
    int ptrB; // ���� ������B. �⺻������ ���� �����ʹ� ���ÿ� �׿� �ִ� �������� ������ ��Ÿ���ٰ� �� �� �ִµ�, �̷��� �ϳ��� �迭 �ȿ��� �� ���� ������ �̿��ϴ� ���, �������� ������ ��Ÿ���ٰ� �����ϱ� ���� ���� �����͸� ������ �ε����� ����ϴ� �뵵��� ����.
    int* stk; // �������� ����� �迭�� ����Ű�� ������
} IntDoubleStack;

// ���� �ʱ�ȭ
int Initialize(IntDoubleStack* s, int max);

// ���ÿ� �����͸� Ǫ��
int Push(IntDoubleStack* s, int sw, int x);

// ���ÿ��� �����͸� ��
int Pop(IntDoubleStack* s, int sw, int* x);

// ���ÿ��� �����͸� ��ũ(top�� ��ġ�ϴ� ��� Ȯ��)
int Peek(const IntDoubleStack* s, int sw, int* x);

// ���� ����
void Clear(IntDoubleStack* s, int sw);

// ������ �ִ� �뷮
int Capacity(const IntDoubleStack* s);

// ������ ������ ����
int Size(const IntDoubleStack* s, int sw);

// ������ ����ֳ���?
int IsEmpty(const IntDoubleStack* s, int sw);

// ������ ���� á����?
int IsFull(const IntDoubleStack* s);

// ���ÿ��� �˻�
int Search(const IntDoubleStack* s, int sw, int x);

// ��� �����͸� ���
void Print(const IntDoubleStack* s, int sw);

// ���� ����
void Terminate(IntDoubleStack* s);


#endif /* IntDoubleStack_h */