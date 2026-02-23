//Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
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
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);
    struct Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;       
            l1 = l1->next;        
        } else {
            tail->next = l2;       
            l2 = l2->next;         
        }
        tail = tail->next;         
    }
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    struct Node* mergedHead = dummy->next;
    free(dummy);                  
    return mergedHead;
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
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    int n;
    printf("enter no of integer ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(&l1, val);
    }
    int m;
    printf("enter intergers for other list ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        insert(&l2, val);
    }
    printf("List 1   : ");
    display(l1);
    printf("List 2   : ");
    display(l2);
    struct Node* merged = mergeSorted(l1, l2);

    printf("Merged   : ");
    display(merged);
    return 0;
}