//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
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
void deleteKey(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;    
        free(temp);            
        printf("Key %d deleted.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;          
        temp = temp->next;    
    }
    if (temp == NULL) {
        printf("Key %d not found in list.\n", key);
        return;
    }
    prev->next = temp->next;   
    free(temp);               
    printf("Key %d deleted\n", key);
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
    printf("enter integer ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        printf("enter value ");
        scanf("%d", &val);
        insert(&head, val);
    }
    int key;
    printf("enter key ");
    scanf("%d", &key);
    printf("Original  : ");
    display(head);
    deleteKey(&head, key);
    printf("After Del : ");
    display(head);

    return 0;
}