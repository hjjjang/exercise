// 2. 하나의 배열을 공유하여 2개의 스택을 구현하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include "IntDoubleStack.h"

// 스택 초기화
int Initialize(IntDoubleStack* s, int max)
{
    s->ptrA = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0; // 배열의 생성에 실패
        s->ptrB = 0;
        return -1;
    }

    s->ptrB = max - 1;
    s->max = max;
    return 0;
}

// 스택에 데이터를 푸시
// 스택이 가득 차서 푸시할 수 없는 경우 -1 반환, 스택에 푸시 성공하면 0을 반환
int Push(IntDoubleStack* s, int sw, int x)
{
    if (s->ptrA >= s->ptrB + 1) // 스택이 가득 참
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

// 스택에서 데이터를 팝
// 스택이 비어 있어 팝 할수 없는 경우 -1 반환, 팝에 성공할 경우 0을 반환
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

// 스택에서 데이터를 피크(top에 위치하고 있는 데이터를 열람)
// 스택이 비어 있으면 -1 반환, 피크에 성공하면 0을 반환
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

// 스택 비우기
// 배열 요소들을 변경할 필요 없음. ptr을 0으로.
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

// 스택 용량
// max의 값 반환. IntDoubleStack이여도 그대로.
int Capacity(const IntDoubleStack* s)
{
    return s->max;
}

// 스택에 쌓여 있는 데이터의 수
// stackB의 경우 ptrB를 이용한 간단한 연산 필요 (ptrA와는 다르게 ptrB는 데이터의 수를 의미하진 못하므로)
// 이럴 때를 대비하여, 스택포인터가 스택에 쌓여 있는 데이터의 개수를 나타낸다기보다, 다음 데이터를 삽입할 인덱스를 기억한다고 생각하면 좋음.
int Size(const IntDoubleStack* s, int sw)
{
    return (sw == stackA) ? s->ptrA : s->max - s->ptrB - 1;
}

// 스택이 비어 있는가?
// 스택이 비어 있으면 1, 그렇지 않으면 0 반환
int IsEmpty(const IntDoubleStack* s, int sw)
{
    return (sw == stackA) ? (s->ptrA <= 0) : (s->ptrB >= s->max - 1);
}

// 스택이 가득 찼는가?
// 스택이 가득 찼으면 1, 그렇지 않으면 0 반환
int IsFull(const IntDoubleStack* s)
{
    return s->ptrA >= s->ptrB + 1;
}

// 스택에서 검색
// 검색에 성공하면 찾은 요소의 인덱스를 반환, 실패하면 -1을 반환
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

    return -1; // 검색 실패
}

// 모든 데이터를 출력
void Print(const IntDoubleStack* s, int sw)
{
    int i;
    switch (sw)
    {
    case stackA:
        for (i = 0; i < s->ptrA; i++) // bottom -> top 방향으로 출력
            printf("%d ", s->stk[i]);
        break;

    case stackB:
        for (i = s->max - 1; i > s->ptrB; i--) // bottom -> top 방향으로 출력
            printf("%d ", s->stk[i]);
        break;
    }
    putchar('\n');
}

// 스택 종료
void Terminate(IntDoubleStack* s)
{
    if (s->stk != NULL)
        free(s->stk); // 배열을 삭제

    s->max = s->ptrA = s->ptrB = 0;
}


#include <stdio.h>
#include "IntDoubleStack.h"

int main() {
    IntDoubleStack s;

    if (Initialize(&s, 12) == -1) {
        puts("스택 생성 실패");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("현재 데이터 개수 : A : %d B : %d / %d\n", Size(&s, stackA), Size(&s, stackB), Capacity(&s));
        printf("1) A에 Push 2) A에서 Pop 3) A에서 Peek 4) A를 출력 5) A에서 검색 6) A를 초기화\n"
            "7) B에 Push 8) B에서 Pop 9) B에서 Peek 10) B를 출력 11) B에서 검색 12) B를 초기화\n""13) 빈 상태 / 가득 찬 상태 0) 종료 : ");

        scanf_s("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: // A에 푸시
            printf("데이터 : ");
            scanf_s("%d", &x);
            if (Push(&s, stackA, x) == -1)
                puts("\a오류 : 푸시 실패");
            break;

        case 2: // A에서 팝
            if (Pop(&s, stackA, &x) == -1)
                puts("\a오류 : 팝 실패");
            else
                printf("팝한 데이터는 %d입니다.\n", x);
            break;

        case 3: // A에서 피크
            if (Peek(&s, stackA, &x) == -1)
                puts("\a오류 : 피크 실패");
            else
                printf("피크한 데이터는 %d입니다.\n", x);
            break;

        case 4: // A 출력
            Print(&s, stackA);
            break;

        case 5: // A에서 검색
            printf("검색 데이터 : ");
            scanf_s("%d", &x);
            if ((idx = Search(&s, stackA, x) == -1))
                puts("\a오류 : 검색 실패");
            else
                printf("데이터는 인덱스 %d에 있습니다.\n", idx);
            break;

        case 6: // A 초기화
            Clear(&s, stackA);
            break;

        case 7: // B에 푸시
            printf("데이터 : ");
            scanf_s("%d", &x);
            if (Push(&s, stackB, x) == -1)
                puts("\a오류 : 푸시 실패");
            break;

        case 8: // B에서 팝
            if (Pop(&s, stackB, &x) == -1)
                puts("\a오류 : 팝 실패");
            else
                printf("팝한 데이터는 %d입니다.\n", x);
            break;

        case 9: // B에서 피크
            if (Peek(&s, stackB, &x) == -1)
                puts("\a오류 : 피크 실패");
            else
                printf("피크한 데이터는 %d입니다.\n", x);
            break;

        case 10: // B 출력
            Print(&s, stackB);
            break;

        case 11: // B에서 검색
            printf("검색 데이터 : ");
            scanf_s("%d", &x);
            if ((idx = Search(&s, stackB, x) == -1))
                puts("\a오류 : 검색 실패");
            else
                printf("데이터는 인덱스 %d에 있습니다.\n", idx);
            break;

        case 12: // B 초기화
            Clear(&s, stackB);
            break;

        case 13: // 빈 상태 / 가득 찬 상태 판단
            printf("스택 A는 비어 %s.\n", IsEmpty(&s, stackA) ? "있습니다" : "있지 않습니다");
            printf("스택 B는 비어 %s.\n", IsEmpty(&s, stackB) ? "있습니다" : "있지 않습니다");
            printf("스택은 가득 %s.\n", IsFull(&s) ? "찼습니다" : "차지 않았습니다");
            break;
        }

    }
    Terminate(&s);

    return 0;
}