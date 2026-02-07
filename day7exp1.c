// //Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

// Input:
// - Single integer n

// Output:
// - Print the n-th Fibonacci number

// Example:
// Input:
// 6

// Output:
// 8

// Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6
#include<stdio.h>
int fibo(int n);
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf(" %d\n", fibo(n));
        return 0;
    }
int fibo(int n){
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    int fibn1=fibo(n-1);
    int fibn2=fibo(n-2);
    int fib=fibn1 + fibn2;
    return fib;
}
