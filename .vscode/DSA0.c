#include <stdio.h>
// #define MAX_SIZE 100

// // 定义栈结构
// typedef struct {
//     int data[MAX_SIZE];
//     int top;
// } Stack;

// // 初始化栈
// void initStack(Stack *s) {
//     s->top = -1;
// }

// // 入栈操作
// void push(Stack *s, int x) {
//     if(s->top < MAX_SIZE-1) {
//         s->data[++(s->top)] = x;
//     }
// }

// // 出栈操作
// int pop(Stack *s) {
//     if(s->top >= 0) {
//         return s->data[(s->top)--];
//     }   
//     return -1;
// }

// int main() {
//     Stack s;
//     initStack(&s);
    
//     int num1, num2, num3;
//     scanf("%d %d %d", &num1, &num2, &num3);
    
//     // 入栈
//     push(&s, num1);
//     push(&s, num2);
//     push(&s, num3);
    
//     // 出栈并打印
//     printf("%d %d %d\n", pop(&s), pop(&s), pop(&s));
    
//     return 0;
// }
int main(){
    printf("hello world\n");
    int n=0; 
    scanf("%d",&n);
    printf("%d",n);
    return 0;
}
