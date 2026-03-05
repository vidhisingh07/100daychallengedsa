//Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10
#include <stdio.h>
int stack[100];
int top = -1;
void push(int data) {
    top++;
    stack[top] = data;
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    top--;
}
int main() {
    int n, m, val;
    printf("enter integer to push ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }
    printf("enter integer to pop ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}