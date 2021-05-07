// ��ǥ : N���� ������ N-1���� �����͸� Enqueue, Dequeue�� �� �ִ� ť ����
// 1. ������ �迭 ������ ȿ�������� ����ϱ� ���� ���
//   - ������ �����ڸ� ���, ���� �ε����� ������ �ʰ��� ��� �ٽ� 0���� ���ư��� 
// 2. N-1���� ����ϴ� ����
// front == rear ť�� ����ִ� ���� or �� �� �ִ� ���� ������ �ȵǴ� ���� �ذ�
// +@: �������� ������ ������� ����ִ� ���� & �� �� ���¸� ������ ���� ����
#include <stdio.h>

#define QUEUE_SIZE 10      // �ε��� ����: 0~9

typedef struct {
    int queue[QUEUE_SIZE];
    int front, rear;   // ť�� ó���� �� ��ġ�� ����Ű�� �ε��� (�ʱ�ȭ)
} Queue;


// �̽� 1�� ���� �ذ�
int NextPosition(int pos) {
    // 1. ���� �ڵ�
    return(pos + 1) % QUEUE_SIZE;
    // 2. �ǹ̸� ��ġ�ϴ� �ڵ�
    //   if (pos == QUEUE_SIZE - 1)
    //      return 0;
    //   else
    //      return pos + 1;
}

void QueueInit(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void EnQueue(Queue* q, int data) {
    if (NextPosition(q->rear) == q->front) {   // �� á�� ���
        printf("ť�� �����Ͱ� ����\n");
    }
    else {   // �� ���� ���� ���
        q->queue[q->rear] = data;
        q->rear = NextPosition(q->rear);
        // �Լ��� ������� ���� ���
        //rear = (rear + 1) % QUEUE_SIZE;
    }
}

int DeQueue(Queue* q) {
    if (q->front == q->rear) {
        printf("ť�� ���� �����Ͱ� ����\n");
        exit(-1);
    }
    else {
        q->front = NextPosition(q->front);
        int dequeueData = q->queue[q->front];
        return dequeueData;
    }
}

int QueuePeek(Queue* q) {
    if (q->front == q->rear) {
        printf("ť�� ���� �����Ͱ� ����\n");
        exit(-1);
    }
    else {
        return q->queue[NextPosition(q->front)];
    }
}

int main() {
    Queue myQueue, queue23, gsmQueue;
    QueueInit(&myQueue); // myQueue->front = 0; myQueue->rear = 0;
    QueueInit(&queue23); // �ʱ�ȭ

    EnQueue(&myQueue, 1);
    EnQueue(&queue23, 2);
    EnQueue(&myQueue, 3);
    EnQueue(&queue23, 5);

    printf("myQueue���� DeQueue: %d\n", DeQueue(&myQueue));
    printf("queue23���� DeQueue: %d\n", DeQueue(&queue23));

    printf("myQueue���� QueuePeek: %d\n", QueuePeek(&myQueue));
    printf("queue23���� QueuePeek: %d\n", QueuePeek(&queue23));

    printf("myQueue���� QueuePeek: %d\n", QueuePeek(&myQueue));
    printf("queue23���� QueuePeek: %d\n", QueuePeek(&queue23));



