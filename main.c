#include "header.h"

int main() {
    Stack myStack;
    Queue myQueue;
    
    printf("=== TEST ADT STACK ===\n");
    createStack(&myStack);
    
    // Test Push
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    
    // Test Top
    printf("Top elemen saat ini: %d\n", top(myStack));
    
    // Test Pop
    printf("Pop elemen: %d\n", pop(&myStack));
    printf("Top elemen setelah pop: %d\n", top(myStack));
    
    printf("\n=== TEST ADT QUEUE ===\n");
    createQueue(&myQueue);
    
    // Test Enqueue
    enqueue(&myQueue, 100);
    enqueue(&myQueue, 200);
    enqueue(&myQueue, 300);
    
    // Test Head & Tail
    printf("Head Queue: %d\n", head(myQueue));
    printf("Tail Queue: %d\n", tail(myQueue));
    
    // Test Dequeue
    printf("Dequeue elemen: %d\n", dequeue(&myQueue));
    printf("Head setelah dequeue: %d\n", head(myQueue));

    return 0;
}