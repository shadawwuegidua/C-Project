#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 生成不同类型的数组
int* randgenerator(char* T, int* data, int N, int s, int t) {
    if (strcmp(T, "顺序递增") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = s + i * (t - s) / (N - 1);
        }
    } else if (strcmp(T, "顺序递减") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = t - i * (t - s) / (N - 1);
        }
    } else if (strcmp(T, "随机取值") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = s + rand() % (t - s + 1);
        }
    }
    return data;
}

// 插入排序函数
int* InsertionSort(int* data, int N) {
    int temp;
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (data[j] < data[j - 1]) {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
    }
    return data;
}
int* BubbleSort(int* data, int N){
    int i,j,temp;
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(data[j]>data[j+1]){
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;

            }
        }
    }
}
// 打印数组函数
void printArray(int* data, int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int N = 100000;  // 数组大小
    int s = 1;   // 范围下限
    int t = 100000; // 范围上限
    int* data = (int*)malloc(N * sizeof(int));

    if (data == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    // 初始化随机数种子
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;

    // 测试顺序递增数组生成
    printf("顺序递增数组:\n");
    start = clock();
    randgenerator("顺序递增", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("生成顺序递增数组用时: %f 秒\n", cpu_time_used);
    // printArray(data, N);

    // 对顺序递增数组进行排序
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("排序顺序递增数组用时: %f 秒\n", cpu_time_used);
    printf("排序后的顺序递增数组:\n");
    // printArray(data, N);

    // 测试顺序递减数组生成
    printf("顺序递减数组:\n");
    start = clock();
    randgenerator("顺序递减", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("生成顺序递减数组用时: %f 秒\n", cpu_time_used);
    // printArray(data, N);

    // 对顺序递减数组进行排序
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("排序顺序递减数组用时: %f 秒\n", cpu_time_used);
    printf("排序后的顺序递减数组:\n");
    // printArray(data, N);

    // 测试随机取值数组生成
    printf("随机取值数组:\n");
    start = clock();
    randgenerator("随机取值", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("生成随机取值数组用时: %f 秒\n", cpu_time_used);
    // printArray(data, N);

    // 对随机取值数组进行排序
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("排序随机取值数组用时: %f 秒\n", cpu_time_used);
    printf("排序后的随机取值数组:\n");
    // printArray(data, N);

    // 释放内存
    free(data);

    return 0;
}