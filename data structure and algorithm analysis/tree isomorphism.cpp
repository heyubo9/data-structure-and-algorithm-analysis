/*
* 树的同构分析
* create: 2018/12/10
*/
#include <stdio.h>
#include <malloc.h>

typedef struct TreeNode *BinTree;

struct TreeNode
{
	char c;
	BinTree Left;
	BinTree Right;
};

int find_root(int *left, int *right, int nodenum);

int IsIsomorphism(BinTree T1, BinTree T2);

TreeNode *create_node(char *c, int *left, int *right, int index);

BinTree init_tree();

void free_tree(BinTree T)
{
	if (T)
	{
		free_tree(T->Left);
		free_tree(T->Right);
		free(T);
		return;
	}
	return;
}

int IsIsomorphism(BinTree T1, BinTree T2)
{
	if (T1 && T2)
	{
		if (IsIsomorphism(T1->Left, T2->Left) && IsIsomorphism(T1->Right, T2->Right))
		{
			return 1;
		}
		else if (IsIsomorphism(T1->Left, T2->Right) && IsIsomorphism(T1->Right, T2->Left))
		{
			return 1;
		}
		else
			return 0;
	}
	else if (T1 || T2)
		return 0;
	else
		return 1;
}

int find_root(int *left, int *right, int nodenum)
{
	int sum = 0;
	for (int i = 0; i < nodenum; i++)
	{
		if (left[i] != -1)
		{
			sum = sum + left[i];
		}

		if (right[i] != -1)
		{
			sum = sum + right[i];
		}
	}
	int rootindex = (nodenum - 1) * nodenum / 2 - sum;
	return rootindex;
}

TreeNode *create_node(char *c, int *left, int *right, int index)
{
	struct TreeNode *treenode;

	treenode = (TreeNode *)malloc(sizeof(TreeNode));
	treenode->Left = NULL;
	treenode->Right = NULL;
	treenode->c = c[index];
	if(left[index]!=-1)
		treenode->Left = create_node(c, left, right, left[index]);
	if (right[index] != -1)
		treenode->Right = create_node(c, left, right, right[index]);

	return treenode;
}

BinTree init_tree()
{
	int nodenum, root_index;
	char *data;
	int *left_child, *right_child;
	BinTree root;

	printf("input node number:\n");
	scanf("%d\n", &nodenum);
	if (!nodenum)
		return NULL;
	data = (char *)malloc(sizeof(char) * nodenum);
	left_child = (int *)malloc(sizeof(int) * nodenum);
	right_child = (int *)malloc(sizeof(int) * nodenum);
	for (int i = 0; i < nodenum; i++)
	{
		printf("input node information:\n");
 		scanf("%c%d%d\n", &data[i], &left_child[i], &right_child[i]);
	}
	root_index = find_root(left_child, right_child, nodenum);
	root = create_node(data, left_child, right_child, root_index);

	free(data);
	free(left_child);
	free(right_child);
	return root;
}