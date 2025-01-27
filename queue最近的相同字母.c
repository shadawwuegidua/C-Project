// Description

// 使用队列寻找二维数组中曼哈顿距离最近的相同字母。

// 二维数组不大于6*6。


// Input

// 第1行为2个整数，为二维数组的行数和列数。之后按行输入二维数组。


// Output

// 曼哈顿距离最近的字母。


// Sample Input 1 

// 3 3
// a b c
// f e m
// c b a
// Sample Output 1
// Sample Output 1// b
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 6

// 方向数组，用于四个方向的遍历
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// 队列节点
typedef struct {
    int x, y, distance;
} Node;

// 队列结构体
typedef struct {
    Node data[MAX_SIZE * MAX_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// 判断队列是否为空
bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

// 入队操作
void enqueue(Queue* q, int x, int y, int distance) {
    q->rear++;
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->data[q->rear].distance = distance;
}

// 出队操作
Node dequeue(Queue* q) {
    return q->data[q->front++];
}

// 判断位置是否有效
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// 曼哈顿距离搜索函数
int findClosest(char grid[MAX_SIZE][MAX_SIZE], int rows, int cols, char target, int startX, int startY) {
    bool visited[MAX_SIZE][MAX_SIZE] = {false};
    Queue q;
    initQueue(&q);

    // 起始位置入队
    enqueue(&q, startX, startY, 0);
    visited[startX][startY] = true;

    while (!isEmpty(&q)) {
        Node current = dequeue(&q);

        // 检查四个方向
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols) && !visited[newX][newY]) {
                visited[newX][newY] = true;

                // 如果找到相同字母，返回距离
                if (grid[newX][newY] == target) {
                    return current.distance + 1;
                }

                // 否则继续搜索
                enqueue(&q, newX, newY, current.distance + 1);
            }
        }
    }

    return INT_MAX;  // 如果没有找到相同字母
}

int main() {
    int rows, cols;
    char grid[MAX_SIZE][MAX_SIZE];

    // 输入二维数组的行数和列数
    scanf("%d %d", &rows, &cols);

    // 输入二维数组
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }

    char result = '\0';
    int minDistance = INT_MAX;

    // 遍历所有字母，寻找最近的相同字母
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int distance = findClosest(grid, rows, cols, grid[i][j], i, j);
            if (distance < minDistance) {
                minDistance = distance;
                result = grid[i][j];
            }
        }
    }

    // 输出结果
    printf("%c\n", result);

    return 0;
}
