// Description

// 请使用循环链表解决约瑟夫问题。
// 约瑟夫问题为n个人围成一个圆圈，首先第1个人从1开始一个人一个人顺时针报数,报到第m个人，令其出列。然后再从下一个人开始，从1顺时针报数，报到第m个人，再令其出列，…，如此下去,直到圆圈中只剩一个人为止。此人即为优胜者。


// Input

// 输入两个整数n和m，n为总人数，m为将被逐出的报数值。


// Output

// 输出一个整数，为最后优胜者序号。


// Sample Input 1 

// 8 3
// Sample Output 1

// 7
#include <stdio.h>
#include <stdlib.h>

// 定义循环链表节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 创建循环链表
Node* createCircularList(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = head; // 链表成环
    return head;
}

// 解决约瑟夫问题
int josephus(int n, int m) {
    if (n == 1) return 1;

    Node* head = createCircularList(n);
    Node* prev = NULL;

    // 循环直到只剩下一个节点
    while (head->next != head) {
        // 报数到 m-1 的位置
        for (int i = 1; i < m; i++) {
            prev = head;
            head = head->next;
        }
        // 删除第 m 个节点
        prev->next = head->next;
        free(head);
        head = prev->next;
    }

    int winner = head->data;
    free(head); // 释放最后一个节点
    return winner;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int result = josephus(n, m);
    printf("%d\n", result);

    return 0;
}
