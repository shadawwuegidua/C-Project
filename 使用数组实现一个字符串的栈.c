#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 20//这里定义了栈的最大容量


typedef struct{
    char data[MAX_SIZE];//储存元素的数组
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
bool push(Stack *stack, char value){
    if(isFull(stack)){
        return false;// 栈已满，返回溢出错误
    }
    stack->data[++(stack->top)] = value;// 栈顶指针先加1，再赋值
    return true;
}

//弹出元素
bool pop(Stack *stack, char *poppedValue){
    if(isEmpty(stack)){
        return false;
    }
    *poppedValue = stack->data[(stack->top)--];
    return true;
}


//查看栈顶元素
bool top(Stack *stack,char *topvalue){
    if(isEmpty(stack)){
        return false;
    }
    *topvalue = stack->data[stack->top];
    return true;
}

bool beforeprint(char *str){
    Stack stack;
    initStack(&stack);
    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];
        push(&stack,ch);
    }
    return isEmpty(&stack);
}



int main(){
    Stack mystack;
    initStack(&mystack);

    char str[MAX_SIZE];
    scanf("%20s",str);

    
    for(int i=0;i<MAX_SIZE;i++){
        push(&mystack,str[i]);
    }

    //弹出所有元素并打印
    char value;
    while(!isEmpty(&mystack)){
        pop(&mystack,&value);
        printf("%c",value);
    }

    return 0;
}