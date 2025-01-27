// 实现通用数据类型队列的步骤
// 1. 使用 void* 存储数据
// 将 data 定义为 void**，即一个存储指针的数组，每个指针可以指向任何类型的数据。
// 2. 动态内存分配
// 在 enqueue 时，动态分配内存存储数据，并将指针存入 data。
// 在 dequeue 时，释放已出队元素的内存。
// 3. 修改 enqueue 和 dequeue 函数
// enqueue 函数需要传入指向数据的指针。
// dequeue 函数返回存储的数据指针。

// Description

// 请实现一个通用的循环队列。大小上限为10。

// 向循环队列中插入一次数据，然后取出部分元素，之后再次插入数据。


// Input

// 第1行输入数据类型。

// 第2行输入第一次插入循环队列的数据个数。

// 第3行第一次插入循环队列的数据。

// 第4行输入取出的元素个数。

// 第5行输入第二次插入循环队列的数据个数。

// 第6行输入第二次插入循环队列的数据。


// Output

// 最终循环队列中的元素顺序输出。


#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct{
    void* data[MAX_SIZE];
    int front;//对首索引
    int rear;//队尾索引
    int count;//当前队列中的元素数量
}CirQueue;

//初始化队列
void initQueue(CirQueue *queue){
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isEmpty(CirQueue *queue){
    return queue->count == 0;
}

bool isFull(CirQueue *queue){
    return queue->count == MAX_SIZE;
}

bool enqueue(CirQueue *queue, void* value){
    if(isFull(queue)){
        return false;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;//环形队列处理
    queue->data[queue->rear] = value;
    queue->count++;
    return true;
}

bool dequeue(CirQueue *queue, void** poppedValue){
    if(isEmpty(queue)){
        return false;
    }
    *poppedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return true;
}




int getTypeSize(const char* type) {
    if (strcmp(type, "int") == 0) return sizeof(int);
    if (strcmp(type, "float") == 0) return sizeof(float);
    if (strcmp(type, "double") == 0) return sizeof(double);
    if (strcmp(type, "char") == 0) return sizeof(char);
    return 0;  // 默认值
}

// bool peekfront(CirQueue *queue, int *frontValue){
//     if(isEmpty(queue)){
//         return false;
//     }
//     *frontValue = queue->data[queue->front];
// }

// bool peekrear(CirQueue *queue, int *rearValue){
//     if(isEmpty(queue)){
//         return false;
//     }
//     *rearValue = queue->data[queue->rear];
// }

// 打印队列内容
void printQueue(CirQueue *queue, const char* type){
    int index = queue->front;
    for(int i=0;i<queue->count;i++){

        if(strcmp(type, "int") == 0){
            printf("%d ",(*(int*)queue->data[index]));
        }

        if(strcmp(type, "char") == 0){
            printf("%c ",(*(char*)queue->data[index]));
        }

        if(strcmp(type, "double") == 0){
            printf("%lf ",(*(double*)queue->data[index]));
        }

        if(strcmp(type, "float") == 0){
            printf("%f ",(*(float*)queue->data[index]));
        }

        if(strcmp(type, "long long") == 0){
            printf("%lld ",(*(int*)queue->data[index]));
        }

        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}

// 释放队列中的所有动态内存
void clearQueue(CirQueue *queue){
    void* value;
    while(dequeue(queue, &value)){
        free(value);
    }
}

int main(){
    CirQueue queue;
    initQueue(&queue);

    char type[10];
    int firstInsertCount, firstDequeueCount, secondInsertCount;

    scanf("%s",type);
    
    int typeSize = getTypeSize(type);

    scanf("%d", &firstInsertCount);
    for(int i = 0; i < firstInsertCount; i++){
        void* temp = malloc(typeSize);
        if (strcmp(type, "int") == 0) {
            scanf("%d", (int*)temp);
        } else if (strcmp(type, "float") == 0) {
            scanf("%f", (float*)temp);
        } else if (strcmp(type, "double") == 0) {
            scanf("%lf", (double*)temp);
        } else if (strcmp(type, "char") == 0) {
            scanf(" %c", (char*)temp);
        }
        if(!enqueue(&queue,temp)){
            free(temp);
        }
    }

        // 取出部分数据
    scanf("%d", &firstDequeueCount);
    for (int i = 0; i < firstDequeueCount; i++) {
        void* temp;
        if (dequeue(&queue, &temp)) {
            free(temp);
        }
    }

        // 第二次插入数据
    scanf("%d", &secondInsertCount);
    for (int i = 0; i < secondInsertCount; i++) {
        void* temp = malloc(typeSize);
        if (strcmp(type, "int") == 0) {
            scanf("%d", (int*)temp);
        } else if (strcmp(type, "float") == 0) {
            scanf("%f", (float*)temp);
        } else if (strcmp(type, "double") == 0) {
            scanf("%lf", (double*)temp);
        } else if (strcmp(type, "char") == 0) {
            scanf(" %c", (char*)temp);
        }
        if (!enqueue(&queue, temp)) {
            free(temp);
        }
    }
 
    // 打印队列内容
    // printf("Queue contents: ");
    printQueue(&queue, type);

    clearQueue(&queue);
    
    return 0;
}