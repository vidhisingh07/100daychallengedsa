#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}
void pop() {
    if (top == -1) {
        printf("stack underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("stack undernderflow\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}
int main() {
    int n;
    printf("enter integer ");
    scanf("%d", &n);
    while (n--) {
        int choice, value;
printf("enter choice ");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            display();
        }
    }
    return 0;
}