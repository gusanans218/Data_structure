// linkedList.c
// ���Ḯ��Ʈ

#include <stdio.h>

typedef int element;        // int �ڷ����� element��� �̸����� ���

// ���Ḯ��Ʈ�� ���� ����ü(���) ���� (�� ������)
typedef struct _node {
    element data;
    struct _node* next;
} Node;

Node* head, * tail;      // ���Ḯ��Ʈ�� ó���� ���� ����Ű�� ������

// 0. �ʱ�ȭ
void Init() {
    if (head != NULL) {
        Node* cur = head, * freeNode;
        while (cur != NULL) {
            freeNode = cur;
            cur = cur->next;
            printf("%d�� ����� �޸� ��ȯ��\n", freeNode->data);
            free(freeNode);
        }
    }
    head = NULL;
    tail = NULL;
}

// 1. ����
void Insert(element data) {
    // (����) ���ο� ��� �����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // ���Ḯ��Ʈ�� ó�� ������ ���� �׷��� ���� ���� ������ ����
    if (head == NULL) {
        head = newNode;
    }
    else {    // ���Ḯ��Ʈ�� �̹� �����Ͱ� ������ ��
        tail->next = newNode;
    }
    tail = newNode;
}

// 1-1 ���ĵ� ����
void SortInsert(element d) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // ��������������������������
    newNode->data = d;                              // ��   d   �� n ��
    newNode->next = NULL;                           // ��������������������������

    if (head == NULL) {      // ù ������ ����
        head = newNode;
        tail = newNode;
    }
    else if (head->data > d) {           // ù ��° ��ġ�� ����
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* cur = head;   // cur->next ���� d�� ��, else if������ ù �� ��ħ
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

// 2. ����
void Delete(element delData) {
    Node* prev = NULL;  // previous(����)�� ���� ����
    Node* cur = head;
    Node* delNode = NULL;   // ����� ���� ��带 ����Ŵ (free�� ����)

    if (cur == NULL) {
        printf("���Ḯ���� ������ ���� X");
        return -1;
    }

    while (cur != NULL) {
        // case1 -> ù ��° ��带 ����� ���� ��
        if (delData == head->data) {
            delNode = cur;
            head = head->next;
            cur = head;
            free(delNode);
        }
        else if (delData == cur->data && cur != head) { // �� ��° ������ ��带 �����
            if (cur == tail) {   // ���� ���� ��尡 ������ �����
                tail = prev;
            }
            delNode = cur;  // ���� free�� �ϱ� ���ؼ�
            prev->next = cur->next;
            cur = cur->next;
            free(delNode);
        }
        else {    // ��带 �������� �ʴ� ���
            prev = cur;
            cur = cur->next;
        }
    }
}

// 3. ��ȸ
void Print() {
    Node* cur = head;
    if (cur == NULL) {
        printf("���Ḯ��Ʈ�� �����Ͱ� �������� ����");
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
    // SortInsert�� ����Ϸ��� �ߺ��� ���� ������ �ϰ�
    // ó������ ������ ��� �������� ��
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
