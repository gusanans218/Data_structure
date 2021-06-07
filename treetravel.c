#include <stdio.h>

// 트리의 순회를 구현
//1. 배열로 표현된 이진트리
//  배열 공간에 야수를 저장(0은 자료가 없는 상태)
#define SIZE 10
int tree[SIZE] = { -1,1,2,3,4,5,6,7,0, 8 };
// 전위순회 : 현재인덱스 읽기 -> 현재인덱스*2 읽기 -> 현재인덱스*2+1 읽기
void preOrder(int* tree, int idx) {
    if (tree[idx] != 0) {
        printf("%d인덱스 방문:[%d]\n", idx, tree[idx]);
    }
    if (idx * 2 < SIZE)
        preOrder(tree, idx * 2);
    if (idx * 2 + 1 < SIZE)
        preOrder(tree, idx * 2 + 1);
}
// 중위순회 : 현지인덱스*2 읽기-> 현재인덱스 읽기->현재인덱스*2+1 읽기
// 후위순회 : 현재인덱스*2읽기 -> 현재인덱스*2+1 읽기 -> 현재인덱스 읽기
int main() {
    preOrder(tree, 1);
}
//2. 노드로 표현된 이진트리