#include "Heap.h"

MinHeap BuildMinHeap(int Capacity)
{
	MinHeap heap;

	heap = (MinHeap)malloc(sizeof(struct Heap));
	if (!heap)
	{
		printf("create minimum heap failed!\n");
		return NULL;
	}

	heap->data = (int *)malloc(sizeof(int)*(Capacity+1));
	if (!heap->data)
	{
		printf("create data array in heap failed\n");
		free(heap);
		return NULL;
	}

	//Initialize the heap
	heap->Capacity = Capacity;
	printf("input data num:\n");
	scanf("%d", &(heap->size));
	if (heap->Capacity < heap->size)
	{
		printf("Minimum Heap cannot contain too much value: Capacity : %d", heap->Capacity);
		free(heap);
		return NULL;
	}
	heap->data[0] = MIN;
	for (int i = 1; i <= heap->size; i++)
	{
		printf("input number:\n");
		scanf("%d", &(heap->data[i]));
	}

	//Build MinHeap
	for (int i = heap->size / 2; i > 0; i--)
	{
		PercolateDown(heap, i);
	}
	if(heap->size > 0)
	{
		heap->data[0] = heap->data[1];
	}
	return heap;
}

void PercolateDown(MinHeap heap, int i)
{
	int Child,j;
	int lastvalue = heap->data[i];

	for (j = i; j * 2 <= heap->size; j = Child)
	{
		//find smaller child
		Child = j * 2;
		if (Child != heap->size && heap->data[Child] > heap->data[Child + 1]) { Child++; }
		
		//Percolate one level
		if (lastvalue > heap->data[Child])
		{
			heap->data[j] = heap->data[Child];
		}
		else { break; }
	}
	heap->data[j] = lastvalue;

	return;
}

int IsFull(MinHeap heap)
{
	if (heap->size == heap->Capacity) { return 1; }
	else { return 0; }
}

int IsEmpty(MinHeap heap)
{
	if (heap->size == 0) { heap->data[0] = MIN; return 1; }
	else { return 0; }
}

int DeleteMin(MinHeap heap)
{
	int min;

	if (IsEmpty(heap))
	{
		printf("heap is empty\n");
		return heap->data[0];
	}
	heap->data[1] = heap->data[heap->size--];
	PercolateDown(heap, 1);
	min = heap->data[0];
	if (heap->size == 0)
	{
		heap->data[0] = MIN;
	}
	else
	{
		heap->data[0] = heap->data[1];
	}
	return min;
}

void Insert(MinHeap heap, int data)
{
	int i;
	if (IsFull(heap))
	{
		printf("minimum heap is full\n");
		return;
	}

	for (i = ++heap->size; data < heap->data[i / 2]; i /= 2)
	{
		heap->data[i] = heap->data[i / 2];
	}
	heap->data[i] = data;
	return;
}