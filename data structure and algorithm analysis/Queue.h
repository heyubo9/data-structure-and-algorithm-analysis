#pragma once

#include <stdio.h>
#include <malloc.h>

typedef struct LQueue *Queue;
typedef struct Node *Head, *Rear;

struct LQueue
{
	int size;
	int MAXSIZE;
	Head head;
	Rear rear;
};

struct Node
{
	int Data;
	Node *next;
};

int IsEmpty(Queue queue_ptr);

Queue QueueInit(int MaxSize);

void EnQueue(int data, Queue queue_ptr);

int DeQueue(Queue queueptr);