//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
int main() {
    int n, m;
    printf("enter integer for list 1 ");
    scanf("%d", &n);
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;
    int arr1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    printf("enter integer for list 2 ");
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    int intersectIndex = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                intersectIndex = i;
                break;
            }
        }
        if (intersectIndex != -1)
            break;
    }
    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr1[i]);
        if (head1 == NULL)
            head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    Node* intersectNode = NULL;
    if (intersectIndex != -1) {
        intersectNode = head1;
        for (int i = 0; i < intersectIndex; i++)
            intersectNode = intersectNode->next;
    }
    for (int i = 0; i < m; i++) {
        if (intersectNode != NULL && arr2[i] == intersectNode->data) {
            tail2->next = intersectNode;
            break;
        }
        Node* newNode = createNode(arr2[i]);
        if (head2 == NULL)
            head2 = tail2 = newNode;
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    Node* result = getIntersection(head1, head2);
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("no intersection\n");
    return 0;
}