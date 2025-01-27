#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 10

typedef struct{
    int data[MAX_SIZE];
    int front;//对首索引
    int rear;//队尾索引
    int count;//当前队列中的元素数量
}Queue;

//初始化队列
void initQueue(Queue *queue){
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isEmpty(Queue *queue){
    return queue->count == 0;
}

bool isFull(Queue *queue){
    return queue->count == MAX_SIZE;
}

bool enqueue(Queue *queue, int value){
    if(isFull(queue)){
        return false;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;//环形队列处理
    queue->data[queue->rear] = value;
    queue->count++;
    return true;
}

bool dequeue(Queue *queue, int *poppedValue){
    if(isEmpty(queue)){
        return false;
    }
    *poppedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return true;
}

bool peekfront(Queue *queue, int *frontValue){
    if(isEmpty(queue)){
        return false;
    }
    *frontValue = queue->data[queue->front];
}

bool peekrear(Queue *queue, int *rearValue){
    if(isEmpty(queue)){
        return false;
    }
    *rearValue = queue->data[queue->rear];
}

int main(){
    Queue queue;
    initQueue(&queue);

    for(int i = 0; i <= 12;i++){
        int temp;
        scanf("%d ",&temp);
        if(enqueue(&queue,temp)){
            printf("Enqueued: %d\n",temp);
        }else{
            printf("Queue is full, cannot enqueue %d\n",temp);
        }
    }

    int value;
    while(dequeue(&queue,&value)){
        printf("Dequeued: %d\n",value);
    }
    
    return 0;
}