// arrayList.c

#include <stdio.h>

#define MAX_SIZE 200    // �迭��� ����Ʈ�� ���� �� �ִ� �ִ��� ������ ����
typedef int ArrayList;  // ������ ���� ��� ����Ʈ�� ArrayList��� �̸�����
typedef int element;

ArrayList list[MAX_SIZE];
int num_of_data = 0;

// 0. �ʱ�ȭ
void Init(ArrayList list[]) {
    num_of_data = 0;
}

// 1. ����
void Insert(ArrayList list[], element inputData) {
    // 1. ����Ʈ�� ������ ������� Ȯ���Ѵ�.
    // 1-1. ������� ������ ����
    // 1-2. ����ϸ� �����͸� �־���
    if (num_of_data == MAX_SIZE) { // 1-1
        printf("����Ʈ�� ������ �����մϴ�\n");
        return -1;
    }
    else {
        list[num_of_data] = inputData;
        num_of_data += 1;
    }
}

// 2. ����
void Delete(ArrayList list[], element delData) {
    if (num_of_data == 0) {
        printf("����Ʈ�� �����Ͱ� ����.\n");
        return -1;
    }
    for (int i = 0; i < num_of_data; i++) {  // Ž���� ���� �ݺ���
        if (list[i] == delData) {
            for (int j = i; j < num_of_data; j++) {
                list[j] = list[j + 1];
            }   // ����Ʈ�� ��������(�����Ͱ� ���������� ����)�� �����ֱ� ����
            num_of_data--;
            i--;
        }
    }
}

// 3. ����
void Change(ArrayList list[], element targetData, element changeData) {
    if (num_of_data == 0) {
        printf("����Ʈ�� �����Ͱ� ����.\n");
        return -1;
    }
    for (int i = 0; i < num_of_data; i++) {  // Ž���� ���� �ݺ���
        if (list[i] == targetData) {
            list[i] = changeData;
        }
    }
}

// 4. ���
void Print(ArrayList list[]) {
    if (num_of_data == 0) {
        printf("����� �����Ͱ� ����Ʈ�� �������� ����\n");
        return -1;
    }
    for (int i = 0; i < num_of_data; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    Init(list);

    Insert(list, 1);
    Insert(list, 1);
    Insert(list, 2);
    Insert(list, 1);
    Insert(list, 3);
    Insert(list, 4);
    Insert(list, 5);
    Insert(list, 1);

    Print(list);

    Change(list, 2, 10);

    Print(list);

    Delete(list, 1);

    Print(list);
}

