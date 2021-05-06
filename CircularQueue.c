//목표 : 0개의 공간에 N-1 데이터를 Enqueue, Dequeue할 수 있는 큐 구현
// 1. 한정된 배열 공간을 효율적으로 사용하기 위한 방법?
// -나머지 연산자를 사용한 다음 인덱스가 범위를 초과할 경우 다시 0으로 돌아가게 한다
// 2. N-1개를 사용하는 이유??
//front == rear 큐가 비어있는 상태 or 꽉 차 있는 상태 구분이 안 되는 문제 해결
// +@: 데이터의 갯수를 기반으로 비어있는 상태 & 꽉 찬 상태를 구분할 수도 있음

#include<stdio.h>
#define QUEUE_SIZE 10 //인덱스 범위 : 0~9
int front = 0, rear = 0; //큐의 처음과 끝 위치를 가리키는 인덱스(초기화)
int queue[QUEUE_SIZE] = { 0 };

//이슈 1에 대한 해결
int NextPosition(int pos) {
	//1. 정석 코드
	return (pos + 1) % QUEUE_SIZE;

	//2. 꼼수 코드(의미만 일치)
	/*if (pos == QUEUE_SIZE -1) {
		return 0;
	}
	else
		return pos + 1;*/
}

void Enqueue(int data) {
	if(NextPosition(rear)==front) {//꽉 찼을 경우
		printf("큐에 데이터가 꽉 참 \n");
	}
	else {	//꽉 차지 않은 경우
		queue[rear] = data;
		rear = NextPosition(rear);
		//rear = (rear+1) % QUEUE_SIZE;
	}
}

int Dequeue() {
	if (front == rear) {
		printf("큐에 꺼낼 데이터가 없음\n");
		exit(-1);
	}
	else {
		int dequeueData = queue[front];
		front = NextPosition(front);
		return dequeueData;
	}
}

int main() {
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Enqueue(6);
	Enqueue(7);
	printf("%d\n", Dequeue());
	printf("%d\n", Dequeue());
	Enqueue(8);
	Enqueue(9);
	Enqueue(10);
	Enqueue(11);
	Enqueue(12);

}