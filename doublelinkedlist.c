// doubleLinkedList.c
// 양방향 연결리스트의 예제

#include <stdio.h>

typedef int element;        // int 자료형을 element라는 이름으로 사용

// 양방향 연결리스트를 위한 구조체(노드) 정의 (및 재정의)
typedef struct _node {
    struct _node* prev;
    element data;
    struct _node* next;
} Node;

int main() {
    Node* prevNode = (Node*)malloc(sizeof(Node));
    Node* nextNode = (Node*)malloc(sizeof(Node));
    prevNode->data = 1;
    prevNode->prev = NULL;          // 현재 상태
    prevNode->next = nextNode;      //  prevNode            nextNode
    nextNode->data = 3;             //  ┌──┌───────┐──┐---→ ┌──┌───────┐──┐
    nextNode->prev = prevNode;      //  │N │   1   │  │     │  │   3   │ N│
    nextNode->next = NULL;          //  └──└───────┘──┘ ←---└──└───────┘──┘

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 2;

    /* 목표 상태
    //  prevNode                                nextNode
    //  ┌──┌───────┐──┐---→ ┌──┌───────┐──┐---→ ┌──┌───────┐──┐
    //  │N │   1   │  │     │  │   2   │  │     │  │   3   │ N│
    //  └──└───────┘──┘ ←---└──└───────┘──┘ ←---└──└───────┘──┘
    //                      newNode
    */

    // prevNode와 newNode 변수만을 이용해서 '현재 상태'에서 '목표 상태'가 되도록
    // 양뱡향 연결 리스트를 연결하시오.
    // 코드 작성 부분 (4줄) ↓




    // 코드 작성 부분 ↓

    // 코드 검증 부분 (수정 X)
    printf("prevNode에서부터 정방향 조회: ");
    Node* cur = prevNode;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n\n");

    printf("nextNode에서부터 역방향 조회: ");
    cur = nextNode;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    //

}
