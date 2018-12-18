#pragma once
/*
* �ѵĽ���
* create: 2018/12/11
*
*/
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 128
#define MIN -127

typedef struct Heap *MinHeap, *MaxHeap;

struct Heap
{
	int *data = NULL;
	int Capacity;
	int size;
};

MinHeap BuildMinHeap(int Capacity);

void Insert(MinHeap heap, int data);

int DeleteMin(MinHeap heap);

int IsFull(MinHeap heap);

int IsEmpty(MinHeap heap);

/*
* �Ե�i���ڵ�����
*/
void PercolateDown(MinHeap heap, int i);