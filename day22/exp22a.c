//Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->next != NULL)
            printf("%d ", temp->data);
        else
            printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;

    int n;
    printf("enter n ");
    scanf("%d", &n);

    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&head, val);
    }
    display(head);

    return 0;
}