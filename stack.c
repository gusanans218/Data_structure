include <stdio.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;

void StackInit() {
    top = -1;
}

void SPush(int inputData) {
    if (top == STACK_SIZE - 1) {
        printf("스택이 가득참\n");
    }
    else {
        top++;
        stack[top] = inputData;
    }
}

int SPop() {
    if (top == -1) {
        printf("스택에 꺼낼 데이터가 없음\n");
        exit(-1);   // 강제 종료
    }
    else {
        int popData = stack[top];
        top--;
        return popData;
    }
}

int SPeek() {
    if (top == -1) {
        printf("스택에 확인할 데이터가 없음\n");
        exit(-1);   // 강제 종료
    }
    else
        return stack[top];
}

int main() {
    StackInit();
    SPush(1);
    SPush(2);
    SPush(3);
    SPush(4);
    SPush(5);
    SPush(6);   // StackOverflow가 발생, 예외처리
    printf("Pop한 데이터: %d\n", SPop());
    printf("Peek한 데이터: %d\n", SPeek());
    printf("Pop한 데이터: %d\n", SPop());
    printf("Peek한 데이터: %d\n", SPeek());
    printf("Pop한 데이터: %d\n", SPop());
    printf("Pop한 데이터: %d\n", SPop());
    printf("Pop한 데이터: %d\n", SPop());
    printf("Pop한 데이터: %d\n", SPop());   // StackUnderflow 발생, 예외처리, 강제종료
}