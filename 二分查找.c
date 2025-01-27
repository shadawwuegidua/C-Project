#include <stdio.h>

// 查找最后一个相同数字的下标
int findLastIndex(int arr[], int n, int x){
    int low = 0, high = n - 1;
    int result = -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            result=mid;// 更新结果为当前下标,防止一直循环下去
            low=mid+1;// 向右移动以查找最后一个出现的下标
        }else if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return result;
}
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int index = findLastIndex(arr, n, x);
    printf("%d\n", index);

    return 0;
}
