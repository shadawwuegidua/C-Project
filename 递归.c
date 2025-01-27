#include<stdio.h>

int factorial(int n){
    /*    
Pre:  The parameter n is a nonnegative integer.
Post: The function returns the nth Fibonacci number.
*/

    if(n <= 0){
        return 1;
    }else{
        return n*factorial(n-1);
    }

}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",factorial(n));
    return 0;
}