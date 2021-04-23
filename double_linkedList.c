// doubleLinkedList.c
// 양방향 연결리스트

#include <stdio.h>

typedef int element;        // int 자료형을 element라는 이름으로 사용

// 양방향 연결리스트를 위한 구조체(노드) 정의 (및 재정의)
typedef struct _node {
    struct _node* prev;
    element data;
    struct _node* next;
} Node;

Node* head, * tail;      // 연결리스트의 처음과 끝을 가리키는 포인터

// 0. 초기화
void Init() {
    if (head != NULL) {
        Node* cur = head, * freeNode;
        while (cur != NULL) {
            freeNode = cur;
            cur = cur->next;
            printf("%d가 저장된 메모리 반환함\n", freeNode->data);
            free(freeNode);
        }
    }
    head = NULL;
    tail = NULL;
}

// 1. 삽입
void Insert(element data) {
    // (공통) 새로운 노드 만들기
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // 연결리스트를 처음 구성할 때와 그렇지 않을 때를 나누어 구현
    if (head == NULL) {
        head = newNode;
    }
    else {    // 연결리스트에 이미 데이터가 존재할 때
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
}

// 2. 삭제
void Delete(element delData) {
    Node* cur = head;
    Node* delNode = NULL;   // 지우고 싶은 노드를 가리킴 (free를 위해)

    if (cur == NULL) {
        printf("연결리슽에 데이터 존재 X");
        return -1;
    }

    while (cur != NULL) {
        printf("현재 노드의 값: %d, ", cur->data);
        // case1 -> 첫 번째 노드를 지우고 싶을 때
        if (delData == head->data) {
            delNode = cur;
            head = head->next;
            cur = head;
            // 지우려는 노드가 유일한 노드가 아닐때만
            // head -> prev 값을 조정해주어야 함
            if (head != NULL) {
                head->prev = NULL;
            }
            free(delNode);
            printf("첫 번째 노드를 삭제함\n");
        }
        else if (delData == cur->data && cur != head) { // 두 번째 이후의 노드를 지우기
            delNode = cur;  // 추후 free를 하기 위해서
            if (cur == tail) {   // 만약 지울 노드가 마지막 노드라면
                tail = tail->prev;
                tail->next = NULL;
                cur = tail->next;
                printf("마지막 노드를 삭제함\n");
            }
            else {    // 중간에 끼어있는 노드를 삭제할 경우
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur = cur->next;
                printf("사이에 끼어있는 노드를 삭제함\n");
            }
            free(delNode);
        }
        else {    // 노드를 삭제하지 않는 경우
            cur = cur->next;
            printf("노드를 삭제하지 않음\n");
        }
    }
}

// 3. 조회
void Print() {
    Node* cur = head;
    if (cur == NULL) {
        printf("연결리스트에 데이터가 존재하지 않음");
        return;
    }
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    /**/
    printf("연결리스트의 뒤에서부터 탐색: ");
    cur = tail;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    /**/
    printf("\n\n");
}

int main() {
    Init();

    Insert(2);
    Insert(1);
    Insert(1);
    Insert(1);

    Print();

    Delete(1);

    Print();

    Delete(2);

    Print();

}