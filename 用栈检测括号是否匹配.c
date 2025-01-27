#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100//这里定义了栈的最大容量


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

bool ismatch(char open,char close){
    return (open == '(' && close == ')') || (open == '[' && close == ']')|| (open =='{' && close == '}');
}

bool checkBrackets(char *str){
    Stack stack;
    initStack(&stack);
    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];

        if(ch=='('||ch=='['||ch=='{'){
            push(&stack,ch);
        }else if(ch==')'||ch==']'||ch=='}'){
            char topChar;
            if(!pop(&stack,&topChar)||!ismatch(topChar,ch)){
                return false;//栈为空或括号不匹配
            }
        }
    }
    return isEmpty(&stack);//栈为空表示匹配成功
}
int main(){
    char str[100];
    scanf("%99s",str); // 修正：限制输入字符串的长度以避免溢出
    if(checkBrackets(str) == 1){
        printf("0");
    }else{
        printf("0");
    }
    return 0;
}