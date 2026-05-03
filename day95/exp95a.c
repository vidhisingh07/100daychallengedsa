#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

typedef struct Node {
    float data;
    struct Node* next;
} Node;

Node* insert(Node* head, float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if(!head || head->data >= val) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while(curr->next && curr->next->data < val) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[1000];

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    Node* bucket[BUCKETS] = {NULL};

    for(int i = 0; i < n; i++) {
        int index = arr[i] * BUCKETS;
        bucket[index] = insert(bucket[index], arr[i]);
    }

    int k = 0;
    for(int i = 0; i < BUCKETS; i++) {
        Node* curr = bucket[i];
        while(curr) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}