#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// 链表节点结构体
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// 哈希表结构体
typedef struct HashTable {
    Node** table;
} HashTable;

// 创建节点
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// 初始化哈希表
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->table = (Node**)malloc(sizeof(Node*) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// 哈希函数，这里使用除留余数法
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 插入元素
void insert(HashTable* hashTable, int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        Node* temp = hashTable->table[index];
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 查找元素
Node* search(HashTable* hashTable, int key) {
    int index = hashFunction(key);
    Node* temp = hashTable->table[index];
    while (temp!= NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 打印哈希表
void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable->table[i];
        printf("Bucket %d: ", i);
        while (temp!= NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 主函数
int main() {
    HashTable* hashTable = createHashTable();
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 11);
    printHashTable(hashTable);
    Node* result = search(hashTable, 20);
    if (result!= NULL) {
        printf("Found key: %d\n", result->key);
    } else {
        printf("Key not found\n");
    }
    return 0;
}