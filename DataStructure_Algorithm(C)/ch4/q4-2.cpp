// 2. �ϳ��� �迭�� �����Ͽ� 2���� ������ �����ϴ� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include "IntDoubleStack.h"

// ���� �ʱ�ȭ
int Initialize(IntDoubleStack* s, int max)
{
    s->ptrA = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0; // �迭�� ������ ����
        s->ptrB = 0;
        return -1;
    }

    s->ptrB = max - 1;
    s->max = max;
    return 0;
}

// ���ÿ� �����͸� Ǫ��
// ������ ���� ���� Ǫ���� �� ���� ��� -1 ��ȯ, ���ÿ� Ǫ�� �����ϸ� 0�� ��ȯ
int Push(IntDoubleStack* s, int sw, int x)
{
    if (s->ptrA >= s->ptrB + 1) // ������ ���� ��
        return -1;

    switch (sw) {
    case stackA:
        s->stk[s->ptrA++] = x;
        break;

    case stackB:
        s->stk[s->ptrB--] = x;
        break;
    }
    return 0;
}

// ���ÿ��� �����͸� ��
// ������ ��� �־� �� �Ҽ� ���� ��� -1 ��ȯ, �˿� ������ ��� 0�� ��ȯ
int Pop(IntDoubleStack* s, int sw, int* x)
{

    switch (sw) {
    case stackA:
        if (s->ptrA <= 0)
            return -1;
        *x = s->stk[--s->ptrA];
        break;

    case stackB:
        if (s->ptrB >= s->max - 1)
            return -1;
        *x = s->stk[++s->ptrB];
        break;
    }

    return 0;
}

// ���ÿ��� �����͸� ��ũ(top�� ��ġ�ϰ� �ִ� �����͸� ����)
// ������ ��� ������ -1 ��ȯ, ��ũ�� �����ϸ� 0�� ��ȯ
int Peek(const IntDoubleStack* s, int sw, int* x)
{
    switch (sw) {
    case stackA:
        if (s->ptrA <= 0)
            return -1;
        *x = s->stk[s->ptrA - 1];
        break;

    case stackB:
        if (s->ptrB >= s->max - 1)
            return -1;
        *x = s->stk[s->ptrB + 1];
        break;
    }


    return 0;
}

// ���� ����
// �迭 ��ҵ��� ������ �ʿ� ����. ptr�� 0����.
void Clear(IntDoubleStack* s, int sw)
{
    switch (sw) {
    case stackA:
        s->ptrA = 0;
        break;

    case stackB:
        s->ptrB = s->max - 1;
        break;
    }
}

// ���� �뷮
// max�� �� ��ȯ. IntDoubleStack�̿��� �״��.
int Capacity(const IntDoubleStack* s)
{
    return s->max;
}

// ���ÿ� �׿� �ִ� �������� ��
// stackB�� ��� ptrB�� �̿��� ������ ���� �ʿ� (ptrA�ʹ� �ٸ��� ptrB�� �������� ���� �ǹ����� ���ϹǷ�)
// �̷� ���� ����Ͽ�, ���������Ͱ� ���ÿ� �׿� �ִ� �������� ������ ��Ÿ���ٱ⺸��, ���� �����͸� ������ �ε����� ����Ѵٰ� �����ϸ� ����.
int Size(const IntDoubleStack* s, int sw)
{
    return (sw == stackA) ? s->ptrA : s->max - s->ptrB - 1;
}

// ������ ��� �ִ°�?
// ������ ��� ������ 1, �׷��� ������ 0 ��ȯ
int IsEmpty(const IntDoubleStack* s, int sw)
{
    return (sw == stackA) ? (s->ptrA <= 0) : (s->ptrB >= s->max - 1);
}

// ������ ���� á�°�?
// ������ ���� á���� 1, �׷��� ������ 0 ��ȯ
int IsFull(const IntDoubleStack* s)
{
    return s->ptrA >= s->ptrB + 1;
}

// ���ÿ��� �˻�
// �˻��� �����ϸ� ã�� ����� �ε����� ��ȯ, �����ϸ� -1�� ��ȯ
int Search(const IntDoubleStack* s, int sw, int x)
{
    int i;

    switch (sw) {
    case stackA:
        for (i = s->ptrA - 1; i >= 0; i--) {
            if (s->stk[i] == x)
                return i;
        }
        break;

    case stackB:
        for (i = s->ptrB + 1; i < s->max; i++) {
            if (s->stk[i] == x)
                return i;
        }
        break;
    }

    return -1; // �˻� ����
}

// ��� �����͸� ���
void Print(const IntDoubleStack* s, int sw)
{
    int i;
    switch (sw)
    {
    case stackA:
        for (i = 0; i < s->ptrA; i++) // bottom -> top �������� ���
            printf("%d ", s->stk[i]);
        break;

    case stackB:
        for (i = s->max - 1; i > s->ptrB; i--) // bottom -> top �������� ���
            printf("%d ", s->stk[i]);
        break;
    }
    putchar('\n');
}

// ���� ����
void Terminate(IntDoubleStack* s)
{
    if (s->stk != NULL)
        free(s->stk); // �迭�� ����

    s->max = s->ptrA = s->ptrB = 0;
}


#include <stdio.h>
#include "IntDoubleStack.h"

int main() {
    IntDoubleStack s;

    if (Initialize(&s, 12) == -1) {
        puts("���� ���� ����");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("���� ������ ���� : A : %d B : %d / %d\n", Size(&s, stackA), Size(&s, stackB), Capacity(&s));
        printf("1) A�� Push 2) A���� Pop 3) A���� Peek 4) A�� ��� 5) A���� �˻� 6) A�� �ʱ�ȭ\n"
            "7) B�� Push 8) B���� Pop 9) B���� Peek 10) B�� ��� 11) B���� �˻� 12) B�� �ʱ�ȭ\n""13) �� ���� / ���� �� ���� 0) ���� : ");

        scanf_s("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: // A�� Ǫ��
            printf("������ : ");
            scanf_s("%d", &x);
            if (Push(&s, stackA, x) == -1)
                puts("\a���� : Ǫ�� ����");
            break;

        case 2: // A���� ��
            if (Pop(&s, stackA, &x) == -1)
                puts("\a���� : �� ����");
            else
                printf("���� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: // A���� ��ũ
            if (Peek(&s, stackA, &x) == -1)
                puts("\a���� : ��ũ ����");
            else
                printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: // A ���
            Print(&s, stackA);
            break;

        case 5: // A���� �˻�
            printf("�˻� ������ : ");
            scanf_s("%d", &x);
            if ((idx = Search(&s, stackA, x) == -1))
                puts("\a���� : �˻� ����");
            else
                printf("�����ʹ� �ε��� %d�� �ֽ��ϴ�.\n", idx);
            break;

        case 6: // A �ʱ�ȭ
            Clear(&s, stackA);
            break;

        case 7: // B�� Ǫ��
            printf("������ : ");
            scanf_s("%d", &x);
            if (Push(&s, stackB, x) == -1)
                puts("\a���� : Ǫ�� ����");
            break;

        case 8: // B���� ��
            if (Pop(&s, stackB, &x) == -1)
                puts("\a���� : �� ����");
            else
                printf("���� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 9: // B���� ��ũ
            if (Peek(&s, stackB, &x) == -1)
                puts("\a���� : ��ũ ����");
            else
                printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 10: // B ���
            Print(&s, stackB);
            break;

        case 11: // B���� �˻�
            printf("�˻� ������ : ");
            scanf_s("%d", &x);
            if ((idx = Search(&s, stackB, x) == -1))
                puts("\a���� : �˻� ����");
            else
                printf("�����ʹ� �ε��� %d�� �ֽ��ϴ�.\n", idx);
            break;

        case 12: // B �ʱ�ȭ
            Clear(&s, stackB);
            break;

        case 13: // �� ���� / ���� �� ���� �Ǵ�
            printf("���� A�� ��� %s.\n", IsEmpty(&s, stackA) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
            printf("���� B�� ��� %s.\n", IsEmpty(&s, stackB) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
            printf("������ ���� %s.\n", IsFull(&s) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
            break;
        }

    }
    Terminate(&s);

    return 0;
}