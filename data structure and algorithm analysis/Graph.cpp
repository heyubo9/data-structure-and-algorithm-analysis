#include "Graph.h"

Graph GraphInit()
{
	Graph graph_ptr;

	graph_ptr = (Graph)malloc(sizeof(struct MGraph));
	if (!graph_ptr)
	{
		printf("malloc space error\n");
		return NULL;
	}
	printf("input vertex num\n");
	scanf("%d\n", &(graph_ptr->Vertex));
	printf("input Edge num\n");
	scanf("%d\n", &(graph_ptr->Edge));
	printf("input edge information\n");
	for (int i = 0; i < MAXNODE; i++)
	{
		for (int j = 0; j < MAXNODE; j++)
		{
			graph_ptr->AdjGraph[i][j] = -1;
		}
	}
	for (int i = 0; i < graph_ptr->Edge; i++)
	{
		int source = 0;
		int destination = 0;
		int weight = 0;
		scanf("%d%d%d\n", &source, &destination, &weight);
		if (!weight)
		{
			weight = 1;
		}
		graph_ptr->AdjGraph[source][destination] = weight;
	}
	return graph_ptr;
}

void BFS(Graph G, int startnode)
{
	Queue Q;
	int *visited;
	int V;

	Q = QueueInit(MAXNODE);
	visited = (int *)malloc(sizeof(int)*(G->Vertex));

	for (int i = 0; i < G->Vertex; i++)
	{
		visited[i] = 0;
	}
	EnQueue(startnode, Q);
	visited[startnode] = 1;
	printf("Breadth first result:\n");
	while (!IsEmpty(Q))
	{
		
		V = DeQueue(Q);
		for (int i = 0; i < MAXNODE; i++)
		{
			if (G->AdjGraph[V][i] != -1)
			{
				if (!visited[i])
				{
					EnQueue(i, Q);
					visited[i] = 1;
				}
			}
		}
		printf("%d ", V);
	}
	printf("\n");
}

void Dijkstra(Graph G, int source, int destination)
{
	Queue Q;
	int *path, *dist;
	int V;

	Q = QueueInit(MAXNODE);
	//record from the path
	path = (int *)malloc(sizeof(int)*(G->Vertex));
	//shortest path from source to i
	dist = (int *)malloc(sizeof(int)*(G->Vertex));

	for (int i = 0; i < G->Vertex; i++)
	{
		dist[i] = MAX_DISTINCT;
		path[i] = -1;
	}
	EnQueue(source, Q);
	dist[source] = 0;
	printf("Breadth first result:\n");
	while (!IsEmpty(Q))
	{
		V = DeQueue(Q);
		for (int i = 0; i < MAXNODE; i++)
		{
			if (G->AdjGraph[V][i] != -1)
			{
				if (dist[V] + G->AdjGraph[V][i] < dist[i])
				{
					EnQueue(i, Q);
					dist[i] = dist[V] + G->AdjGraph[V][i];
					path[i] = V;
				}
			}
		}
		printf("%d ", V);
	}
	printf("\n");
}