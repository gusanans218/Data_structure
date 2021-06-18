#include <stdio.h>

//깊이 우선 탐색
//네 가지의 입력 인자를 전달
//그래프의 인접행렬(배열), visit 배열, 정점의 갯수, 시작점)
void DFS(int(*matrix)[7], int* v, int n, int start) {
    v[start] = 1; //방문했음을 체크
    //다른 노드들을 깊이 우선으로 탐색해야함
    //1.start랑 인접해있어야함
    //2. 아직 방문한 적이 없어야한다

    for (int i = 0; i < n; i++) {
        if (v[i] == 0 && matrix[start][i] == 1) {//DFS를 할 조건
            printf("%d -> %d로 이동\n", start, i);
            DFS(matrix, v, n, i);
        }
    }
}


    int main() {
    int map1[5][5] = { {0, 0, 1, 0, 1},
                       {0, 0, 1, 0, 0},
                       {1, 1, 0, 0, 1},
                       {0, 0, 0, 0, 1},
                       {1, 0, 1, 1, 0} }; // 인접행렬
    int visit1[5] = { 0 };    // 방문여부를 체크, 정점의 갯수와 일치해야 함
    int map2[7][7] = { {0, 1, 0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1, 0, 1},
                      {0, 1, 0, 0, 0, 0, 1},
                      {1, 1, 0, 0, 0, 1, 0},
                      {0, 1, 0, 0, 0, 1, 1},
                      {1, 0, 0, 1, 1, 0, 0},
                      {0, 1, 1, 0, 1, 0, 0} };
    int visit2[7] = { 0 };
    int map3[7][7] = { {0, 1, 0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1, 0, 1},
                      {0, 1, 0, 0, 0, 0, 1},
                      {1, 1, 0, 0, 0, 1, 0},
                      {0, 1, 0, 0, 0, 1, 1},
                      {1, 0, 0, 1, 1, 0, 0},
                      {0, 1, 1, 0, 1, 0, 0} };
    int visit3[7] = { 0 };

    DFS(&map3, &visit3, 7, 0);
}