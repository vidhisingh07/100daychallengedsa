#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void stackInit(struct Stack* s) {
    s->top = -1;
}

bool stackEmpty(struct Stack* s) {
    return s->top == -1;
}

void stackPush(struct Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int stackPop(struct Stack* s) {
    return s->data[(s->top)--];
}

int stackPeek(struct Stack* s) {
    return s->data[s->top];
}



typedef struct {
     struct Stack* inbox;   // stack1: for push
    struct Stack* outbox;
} MyQueue;
void pour(MyQueue* obj) {
    if (stackEmpty(obj->outbox)) {
        while (!stackEmpty(obj->inbox)) {
            stackPush(obj->outbox, stackPop(obj->inbox));
        }
    }
}

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->inbox   = (struct Stack*)malloc(sizeof(struct Stack));
    q->outbox  = (struct Stack*)malloc(sizeof(struct Stack));
    stackInit(q->inbox);
    stackInit(q->outbox);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inbox, x);
}

int myQueuePop(MyQueue* obj) {
    pour(obj);
    return stackPop(obj->outbox);
}

int myQueuePeek(MyQueue* obj) {
    pour(obj);
    return stackPeek(obj->outbox);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->inbox) && stackEmpty(obj->outbox);
}

void myQueueFree(MyQueue* obj) {
    free(obj->inbox);
    free(obj->outbox);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/