#include "header.h"

// --- Helper Functions ---

address allocate(infotype X) {
    address P = (address)malloc(sizeof(Node));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void deallocate(address P) {
    free(P);
}

// --- IMPLEMENTASI STACK ---

void createStack(Stack *S) {
    S->top = NULL;
    S->count = 0;
}

bool isEmptyStack(Stack S) {
    return (S.top == NULL);
}

bool isFullStack(Stack S) {
    //boolean (curSize == SIZE_INIT)
    return (S.count == SIZE_INIT);
}

void push(Stack *S, infotype X) {
    if (isFullStack(*S)) {
        printf("Stack Penuh! Tidak bisa push %d\n", X);
        return;
    }

    address P = allocate(X);
    if (P != NULL) {
        // update newElement->next = current top
        P->next = S->top;
        // update top = newElement
        S->top = P;
        S->count++;
        printf("Push Stack: %d\n", X);
    }
}

infotype pop(Stack *S) {
    if (isEmptyStack(*S)) {
        printf("Stack Kosong!\n");
        return -1; // Nilai error
    }

    address P = S->top;
    infotype value = P->info;

    // update top = cur_top->next
    S->top = S->top->next;
    
    // Putus hubungan node lama dan dealokasi
    P->next = NULL;
    deallocate(P);
    S->count--;
    
    return value;
}

infotype top(Stack S) {
    if (isEmptyStack(S)) return -1;
    return S.top->info;
}


// --- IMPLEMENTASI QUEUE ---

void createQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
    Q->count = 0;
}

bool isEmptyQueue(Queue Q) {
    // head == NULL
    return (Q.head == NULL);
}

bool isFullQueue(Queue Q) {
    return (Q.count == SIZE_INIT);
}

void enqueue(Queue *Q, infotype X) {
    if (isFullQueue(*Q)) {
        printf("Queue Penuh! Tidak bisa enqueue %d\n", X);
        return;
    }

    address P = allocate(X);
    if (P != NULL) {
        if (isEmptyQueue(*Q)) {
            // Jika kosong, head dan tail menunjuk ke elemen yang sama
            Q->head = P;
            Q->tail = P;
        } else {
            // update curtail->next = element
            Q->tail->next = P;
            // tail = element
            Q->tail = P;
        }
        Q->count++;
        printf("Enqueue: %d\n", X);
    }
}

infotype dequeue(Queue *Q) {
    if (isEmptyQueue(*Q)) {
        printf("Queue Kosong!\n");
        return -1;
    }

    address P = Q->head;
    infotype value = P->info;

    // head = curhead->next
    Q->head = Q->head->next;
    
    if (Q->head == NULL) {
        // Jika antrian jadi kosong, pastikan tail juga NULL
        Q->tail = NULL;
    }

    // curhead->next = NULL (isolasi node lama)
    P->next = NULL;
    deallocate(P);
    Q->count--;

    return value;
}

infotype head(Queue Q) {
    if (isEmptyQueue(Q)) return -1;
    return Q.head->info;
}

infotype tail(Queue Q) {
    if (isEmptyQueue(Q)) return -1;
    return Q.tail->info;
}
