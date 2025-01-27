#include <stdio.h>
#include <stdlib.h>

// 定义循环链表节点结构
typedef struct Node {
    int data;          // 存储节点的数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 为新节点分配内存
    newNode->data = data;                       // 设置节点数据
    newNode->next = NULL;                       // 初始化指针为空
    return newNode;
}

// 创建循环链表
Node* createCircularList(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = createNode(i); // 创建新节点
        if (head == NULL) {
            head = newNode;           // 如果是第一个节点，设置为头节点
        } else {
            prev->next = newNode;     // 将前一个节点的 next 指向新节点
        }
        prev = newNode;               // 更新前一个节点为当前节点
    }
    prev->next = head; // 链表成环，最后一个节点指向头节点
    return head;
}

// 解决约瑟夫问题
int josephus(int n, int m) {
    if (n == 1) return 1; // 只有一个人时，直接返回

    Node* head = createCircularList(n); // 创建包含 n 个节点的循环链表
    Node* prev = NULL;                  // 用于记录当前节点的前一个节点

    // 循环直到只剩下一个节点
    while (head->next != head) {
        // 报数到第 m-1 个节点
        for (int i = 1; i < m; i++) {
            prev = head;           // 更新前一个节点
            head = head->next;     // 移动到下一个节点
        }
        // 删除第 m 个节点
        prev->next = head->next;   // 跳过当前节点
        free(head);                // 释放当前节点的内存
        head = prev->next;         // 更新头节点为下一个节点
    }

    int winner = head->data; // 最后一个剩下的节点即为优胜者
    free(head);              // 释放最后一个节点
    return winner;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 输入总人数 n 和报数值 m

    int result = josephus(n, m); // 计算优胜者
    printf("%d\n", result);     // 输出结果

    return 0;
}
