#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX
#define MAX_VERTICES 100
#define INF INT_MAX

int parent[MAX_VERTICES];        // �θ���
void set_init(int n) // �ʱ�ȭ
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}
// curr�����ϴ���������ȯ�Ѵ�.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr;             // ��Ʈ
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b)
{
	int root1 = set_find(a); // ���a�Ƿ�Ʈã��
	int root2 = set_find(b); // ���b�Ƿ�Ʈã��
	if (root1 != root2)     // ���Ѵ�. 
		parent[root2] = root1;
}

typedef struct {            // ��������Ÿ���±���ü
	int start, end, weight;
} Edge;
typedef struct {
	int v;    // ��������
	int n;    // ��������
	Edge edges[2 * MAX_VERTICES];
} GraphType;

// �׷����ʱ�ȭ
void graph_init(GraphType* g)
{
	g->n = 0;
	g->v = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
void insert_vertex(GraphType* g, int v)
{
	g->v++;
}

// �������Կ���
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
// qsort()�����Ǵ��Լ�
int compare(const void* a, const void* b)
{
	Edge* x = (struct Edge*)a;
	Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g)
{
	int edge_accepted = 0; // ����������õȰ�����
	int uset, vset; // ����u������v�����չ�ȣ
	Edge e;
	set_init(g->n); // �����ʱ�ȭ
	qsort(g->edges, g->n, sizeof(Edge), compare);
	printf("Kruskal'sMST algorithm\n");
	int i = 0;
	while (edge_accepted < (g->v - 1)) {
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) { // ���μ��������̴ٸ���
			printf("����(%d,%d) %d ����\n", e.start,
				e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}

intmain(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 7; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	kruskal(g);
	free(g);
	return 0;
}
