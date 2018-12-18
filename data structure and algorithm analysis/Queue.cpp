#include "Queue.h"

int IsEmpty(Queue queue_ptr)
{
	if (!queue_ptr->size)
		return 0;
	else 
		return 1;
}

Queue QueueInit(int MaxSize)
{
	Queue queue_ptr;

	queue_ptr = (Queue)malloc(sizeof(LQueue));
	if (!queue_ptr)
	{
		printf("create queue pointer failure\n");
		return NULL;
	}
	queue_ptr->MAXSIZE = MaxSize;
	queue_ptr->size = 0;
	queue_ptr->head = NULL;
	queue_ptr->rear = NULL;
	return queue_ptr;
}

void EnQueue(int data, Queue queue_ptr)
{
	struct Node *node;

	if (queue_ptr->size == queue_ptr->MAXSIZE)
	{
		printf("EnQueue Failed: Queue is full\n");
		return;
	}

	node = (Node *)malloc(sizeof(struct Node));
	if (!node)
	{
		printf("create node failure\n");
		return;
	}
	node->Data = data;
	node->next = NULL;
	if (!queue_ptr->size)
	{
		queue_ptr->head = node;
	}
	queue_ptr->rear = node;
	queue_ptr->size++;
	return;
}

int DeQueue(Queue queueptr)
{
	struct Node* tmp;
	int tmpdata;

	if (!queueptr->size)
	{
		printf("DeQueue Failed: no enough data\n");
		return -1;
	}
	tmp = queueptr->head;
	queueptr->head = tmp->next;
	tmpdata = tmp->Data;

	queueptr->size--;
	free(tmp);
	return tmpdata;
}