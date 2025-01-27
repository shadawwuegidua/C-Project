#include<string.h>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS  // 添加这一行在文件开头
int main(){
	int n;
	scanf("%d",&n);
	int arr[100000000];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n-1;i++){
		printf("%d ",arr[i]);
	}
	printf("%d\n",arr[n-1]);
	return 0;
}

// Description

// 将读入的N个数从小到大排序后输出。


// Input

// 第一行为一个正整数N。

// 第二行包含N个空格隔开的正整数a_i，为你需要进行排序的数。


// Output

// 将给定的N个数从小到大输出，数之间空格隔开，行末换行且无空格。


// Sample Input 1 

// 5
// 4 2 4 5 1
// Sample Output 1

// 1 2 4 4 5
// Hint

// 对于20%的数据，有1 <= N <= 10^3；

// 对于100%的数据，有1 <= N <= 10^5，1 <= a_i <= 10^9。
