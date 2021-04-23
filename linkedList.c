// linkedList.c
// 연결리스트

#include <stdio.h>

typedef int element;        // int 자료형을 element라는 이름으로 사용

// 연결리스트를 위한 구조체(노드) 정의 (및 재정의)
typedef struct _node {
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
    newNode->next = NULL;

    // 연결리스트를 처음 구성할 때와 그렇지 않을 때를 나누어 구현
    if (head == NULL) {
        head = newNode;
    }
    else {    // 연결리스트에 이미 데이터가 존재할 때
        tail->next = newNode;
    }
    tail = newNode;
}

// 1-1 정렬된 삽입
void SortInsert(element d) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // ┌───────┐───┐
    newNode->data = d;                              // │   d   │ n │
    newNode->next = NULL;                           // └───────┘───┘

    if (head == NULL) {      // 첫 데이터 삽입
        head = newNode;
        tail = newNode;
    }
    else if (head->data > d) {           // 첫 번째 위치로 삽입
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* cur = head;   // cur->next 값과 d를 비교, else if문에서 첫 비교 마침
        while (cur->next != NULL) {
            if (cur->next->data > d) {
                newNode->next = cur->next;
                cur->next = newNode;
                break;
            }
            cur = cur->next;
        }
        cur->next = newNode;
        tail = newNode;
    }
}

// 2. 삭제
void Delete(element delData) {
    Node* prev = NULL;  // previous(이전)의 줄임 형태
    Node* cur = head;
    Node* delNode = NULL;   // 지우고 싶은 노드를 가리킴 (free를 위해)

    if (cur == NULL) {
        printf("연결리슽에 데이터 존재 X");
        return -1;
    }

    while (cur != NULL) {
        // case1 -> 첫 번째 노드를 지우고 싶을 때
        if (delData == head->data) {
            delNode = cur;
            head = head->next;
            cur = head;
            free(delNode);
        }
        else if (delData == cur->data && cur != head) { // 두 번째 이후의 노드를 지우기
            if (cur == tail) {   // 만약 지울 노드가 마지막 노드라면
                tail = prev;
            }
            delNode = cur;  // 추후 free를 하기 위해서
            prev->next = cur->next;
            cur = cur->next;
            free(delNode);
        }
        else {    // 노드를 삭제하지 않는 경우
            prev = cur;
            cur = cur->next;
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
}

int main() {
    Init();

    /*
    // SortInsert를 사용하려면 중복된 값이 없도록 하고
    // 처음부터 끝까지 계속 사용해줘야 함
    SortInsert(5);
    SortInsert(1);
    SortInsert(3);
    SortInsert(2);
    SortInsert(4);
    SortInsert(6);
    */

    Insert(1);
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(1);
    Insert(6);
    Insert(5);
    Insert(1);
    Insert(1);

    Print();

    Delete(1);

    Print();

    Init();

    Print();

}
