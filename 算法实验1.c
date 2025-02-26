#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ���ɲ�ͬ���͵�����
int* randgenerator(char* T, int* data, int N, int s, int t) {
    if (strcmp(T, "˳�����") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = s + i * (t - s) / (N - 1);
        }
    } else if (strcmp(T, "˳��ݼ�") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = t - i * (t - s) / (N - 1);
        }
    } else if (strcmp(T, "���ȡֵ") == 0) {
        for (int i = 0; i < N; i++) {
            data[i] = s + rand() % (t - s + 1);
        }
    }
    return data;
}

// ����������
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
// ��ӡ���麯��
void printArray(int* data, int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int N = 100000;  // �����С
    int s = 1;   // ��Χ����
    int t = 100000; // ��Χ����
    int* data = (int*)malloc(N * sizeof(int));

    if (data == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }

    // ��ʼ�����������
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;

    // ����˳�������������
    printf("˳���������:\n");
    start = clock();
    randgenerator("˳�����", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("����˳�����������ʱ: %f ��\n", cpu_time_used);
    // printArray(data, N);

    // ��˳����������������
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("����˳�����������ʱ: %f ��\n", cpu_time_used);
    printf("������˳���������:\n");
    // printArray(data, N);

    // ����˳��ݼ���������
    printf("˳��ݼ�����:\n");
    start = clock();
    randgenerator("˳��ݼ�", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("����˳��ݼ�������ʱ: %f ��\n", cpu_time_used);
    // printArray(data, N);

    // ��˳��ݼ������������
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("����˳��ݼ�������ʱ: %f ��\n", cpu_time_used);
    printf("������˳��ݼ�����:\n");
    // printArray(data, N);

    // �������ȡֵ��������
    printf("���ȡֵ����:\n");
    start = clock();
    randgenerator("���ȡֵ", data, N, s, t);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("�������ȡֵ������ʱ: %f ��\n", cpu_time_used);
    // printArray(data, N);

    // �����ȡֵ�����������
    start = clock();
    InsertionSort(data, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("�������ȡֵ������ʱ: %f ��\n", cpu_time_used);
    printf("���������ȡֵ����:\n");
    // printArray(data, N);

    // �ͷ��ڴ�
    free(data);

    return 0;
}