// Description

// 请实现一个通用的循环队列。大小上限为10。

// 向循环队列中插入一次数据，然后取出部分元素，之后再次插入数据。


// Input

// 第1行输入数据类型。

// 第2行输入第一次插入循环队列的数据。

// 第3行输入取出的元素个数。

// 第4行输入第二次插入循环队列的数据。


// Output

// 最终循环队列中元素的顺序输出。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    void* data[MAX_SIZE];
    int front;  // 队首索引
    int rear;   // 队尾索引
    int count;  // 当前队列中的元素数量
} CirQueue;

// 初始化队列
void initQueue(CirQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isEmpty(CirQueue* queue) {
    return queue->count == 0;
}

bool isFull(CirQueue* queue) {
    return queue->count == MAX_SIZE;
}

bool enqueue(CirQueue* queue, void* value) {
    if (isFull(queue)) {
        return false;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->count++;
    return true;
}

bool dequeue(CirQueue* queue, void** poppedValue) {
    if (isEmpty(queue)) {
        return false;
    }
    *poppedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return true;
}

// 获取数据类型的大小
int getTypeSize(const char* type) {
    if (strcmp(type, "int") == 0) return sizeof(int);
    if (strcmp(type, "float") == 0) return sizeof(float);
    if (strcmp(type, "double") == 0) return sizeof(double);
    if (strcmp(type, "char") == 0) return sizeof(char);
    return 0;
}

// 打印队列内容
void printQueue(CirQueue* queue, const char* type) {
    int index = queue->front;
    for (int i = 0; i < queue->count; i++) {
        if (strcmp(type, "int") == 0) {
            printf("%d ", *(int*)queue->data[index]);
        } else if (strcmp(type, "float") == 0) {
            printf("%.2f ", *(float*)queue->data[index]);
        } else if (strcmp(type, "double") == 0) {
            printf("%.2lf ", *(double*)queue->data[index]);
        } else if (strcmp(type, "char") == 0) {
            printf("%c ", *(char*)queue->data[index]);
        }
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}

// 清空队列并释放内存
void clearQueue(CirQueue* queue) {
    void* value;
    while (dequeue(queue, &value)) {
        free(value);
    }
}

int main() {
    CirQueue queue;
    initQueue(&queue);

    char type[10];
    int typeSize;
    int dequeueCount;

    // 输入数据类型
    scanf("%s", type);
    typeSize = getTypeSize(type);

    // 第一次插入数据
    char firstInsertData[256];
    scanf(" %[^\n]", firstInsertData);  // 读取整行数据
    char* token = strtok(firstInsertData, " ");//strtok函数是C语言标准库中的一个函数，用于将字符串分割成一系列子字符串。这个函数定义在<string.h>头文件中。当使用strtok函数时，可以指定一个或多个分隔符，函数会根据这些分隔符将字符串分割，并返回指向第一个子字符串的指针。在后续的调用中，应将第一个参数设置为NULL，以便函数继续从上次结束的位置开始分割字符串。


    while (token != NULL) {
        void* temp = malloc(typeSize);
        if (strcmp(type, "int") == 0) {
            *(int*)temp = atoi(token);
        } else if (strcmp(type, "float") == 0) {
            *(float*)temp = atof(token);
        } else if (strcmp(type, "double") == 0) {
            *(double*)temp = atof(token);
        } else if (strcmp(type, "char") == 0) {
            *(char*)temp = token[0];
        }
        if (!enqueue(&queue, temp)) {
            free(temp);
        }
        token = strtok(NULL, " ");
    }

    // 取出部分数据
    scanf("%d", &dequeueCount);
    for (int i = 0; i < dequeueCount; i++) {
        void* temp;
        if (dequeue(&queue, &temp)) {
            free(temp);
        }
    }

    // 第二次插入数据
    char secondInsertData[256];
    scanf(" %[^\n]", secondInsertData);  // 读取整行数据
    token = strtok(secondInsertData, " ");
    while (token != NULL) {
        void* temp = malloc(typeSize);
        if (strcmp(type, "int") == 0) {
            *(int*)temp = atoi(token);
        } else if (strcmp(type, "float") == 0) {
            *(float*)temp = atof(token);
        } else if (strcmp(type, "double") == 0) {
            *(double*)temp = atof(token);
        } else if (strcmp(type, "char") == 0) {
            *(char*)temp = token[0];
        }
        if (!enqueue(&queue, temp)) {
            free(temp);
        }
        token = strtok(NULL, " ");
    }

    // 输出队列内容
    printQueue(&queue, type);

    // 清空队列
    clearQueue(&queue);

    return 0;
}
