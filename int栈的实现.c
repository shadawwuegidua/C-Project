#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 3//这里定义了栈的最大容量

typedef enum{SUCCESS,OVERFLOW,UNDERFLOW}ErrorCode;
// 这里也可以写成这样
// enum ErrorCode{SUCCESS,OVERFLOW,UNDERFLOW};

typedef struct{
    int data[MAX_SIZE];//储存元素的数组
    int top;//栈顶索引
}Stack;

void initStack(Stack *stack){
    stack->top = -1;//栈顶设置为-1 表示空栈
}

//判断栈是否为空
bool isEmpty(Stack *stack){
    return stack->top == -1;
}

//判断栈是否已满
bool isFull(Stack *stack){
    return stack->top == MAX_SIZE - 1;
}

//压入元素
ErrorCode push(Stack *stack, int value){
    if(isFull(stack)){
        return OVERFLOW;// 栈已满，返回溢出错误
    }
    stack->data[++(stack->top)] = value;// 栈顶指针先加1，再赋值
    return SUCCESS;
}

//弹出元素
ErrorCode pop(Stack *stack, int *poppedValue){
    if(isEmpty(stack)){
        return UNDERFLOW;
    }
    *poppedValue = stack->data[(stack->top)--];
    return SUCCESS;
}
//也可以这么写
ErrorCode pop1(Stack *stack){
    if(stack->top == -1){
        return UNDERFLOW;
    }
    --stack->top;
}

//查看栈顶元素
ErrorCode top(Stack *stack,int *topvalue){
    if(isEmpty(stack)){
        return UNDERFLOW;
    }
    *topvalue = stack->data[stack->top];
    return SUCCESS;
}

int main(){
    Stack mystack;
    initStack(&mystack);

    // //压入一些元素
    // for(int i = 0; i < 18; i++){
    //     ErrorCode result = push(&mystack,i);
    //     if(result == OVERFLOW){
    //         printf("Error: Stack overflow at value %d\n",i);
    //     } else {
    //         printf("%d ",i);
    //     }
    // }
    
    int input[3];
    for(int i=0;i<3;i++){
        scanf("%d",&input[i]);
        ErrorCode result=push(&mystack,input[i]);
    }

    //弹出所有元素并打印
    int value;
    while(!isEmpty(&mystack)){
        if(pop(&mystack,&value) == SUCCESS){
        printf("%d ",value);
        }
    }

    // ErrorCode result = pop(&mystack,&value);
    // if (result == UNDERFLOW){
    //     printf("Error: Stack underflow\n");
    // }

    return 0;
}
