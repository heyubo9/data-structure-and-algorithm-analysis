#include "Graph.h"
#include "Queue.h"
#include "Heap.h"
/*
* Create Time: 2018/12/18
* Update Time: 2018/12/18
* Update Info: ��С�Ѳ���ͨ��
*/

void HeapTest();

int main()
{
	HeapTest();
}

void HeapTest()
{
	//��С�Ѳ���
	MinHeap heap;

	heap = BuildMinHeap(32);
	printf("heap content : \n");
	for (int i = 1; i <= heap->size; i++)
	{
		printf("%d ", (heap->data[i]));
	}
	printf("\n");
	DeleteMin(heap);
	printf("heap content : \n");
	for (int i = 1; i <= heap->size; i++)
	{
		printf("%d ", (heap->data[i]));
	}
	printf("\n");
	Insert(heap, 10);
	printf("heap content : \n");
	for (int i = 1; i <= heap->size; i++)
	{
		printf("%d ", (heap->data[i]));
	}
	printf("\n");
	return;
}