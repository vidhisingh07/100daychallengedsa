#define SIZE 10000
typedef struct {

    int stack[SIZE];
    int minStack[SIZE];  
    int top;
} MinStack;


MinStack* minStackCreate() {
        MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        int currMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currMin) ? val : currMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    obj->top--; 
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/