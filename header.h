#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_INIT 5 // Contoh batas maksimal elemen untuk isFull

// Definisi tipe data elemen (misal integer)
typedef int infotype;

// Definisi Node (Elemen)
typedef struct Node *address;
typedef struct Node {
    infotype info;
    address next;
} Node;

// --- ADT STACK ---
typedef struct {
    address top;
    int count; // Untuk mengecek isFull berdasarkan SIZE_INIT
} Stack;

// Prototipe Stack
void createStack(Stack *S);
address allocate(infotype X);
void deallocate(address P);
bool isEmptyStack(Stack S);
bool isFullStack(Stack S);
void push(Stack *S, infotype X);
infotype pop(Stack *S);
infotype top(Stack S);

// --- ADT QUEUE ---
typedef struct {
    address head;
    address tail;
    int count; // Untuk mengecek isFull (opsional di LL, tapi ada di screenshot)
} Queue;

// Prototipe Queue
void createQueue(Queue *Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue *Q, infotype X);
infotype dequeue(Queue *Q);
infotype head(Queue Q);
infotype tail(Queue Q);

#endif