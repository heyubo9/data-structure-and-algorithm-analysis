#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Queue.h"

#define MAXNODE 255
#define MAX_DISTINCT 256

struct MGraph
{
	int Vertex;
	int Edge;
	int AdjGraph[MAXNODE][MAXNODE];
};

typedef struct MGraph *Graph;

Graph GraphInit();

void BFS(Graph G, int startnode);

void Dijkstra(Graph G, int source, int destination);