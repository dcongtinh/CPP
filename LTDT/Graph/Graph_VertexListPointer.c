#include <stdio.h>
#include <malloc.h>

#define MAX_N 100
#define MAX_M 500

typedef struct Node *NodePointer;

struct Node
{
    int element;
    NodePointer next;
};

typedef struct
{
    NodePointer header;
    int size;
} List;

typedef struct
{
    List adj[MAX_N]; //m?ng các danh sách
    int n, m;
} Graph;

void make_null_list(List *L)
{
    L->header = NULL;
    L->size = 0;
}

NodePointer MakeNode(int x)
{
    NodePointer P = (NodePointer)malloc(sizeof(struct Node));
    P->element = x;
    P->next = NULL;
    return P;
}

void print_list(List *L)
{
     NodePointer Header = L->header;
     while (Header != NULL)
     {
         printf("%d ", Header->element);
         Header = Header->next;
     }
     printf("\n");
}

int len(List *L)
{
    return L->size;
}

void push_back(List *L, int x)
{
    NodePointer P = MakeNode(x);

    if (L->header == NULL)
    {
        L->header = P;
        L->size++;
        return;
    }
     NodePointer Header = L->header;
     while (Header->next != NULL)
     {
         Header = Header->next;
     }
     Header->next = P;
     L->size++;  
}

void init_graph(Graph *pG, int n, int m)
{
    int i;
    for (i = 1; i <= n; ++i)
        make_null_list(&pG->adj[i]);
    pG->n = n;
    pG->m = m;
}

void add_edge(Graph *pG, int x, int y)
{
	push_back(&pG->adj[x], y);
	push_back(&pG->adj[y], x);
}

int degree(Graph *pG, int x)
{
    return pG->adj[x].size;
}

int adjacent(Graph *pG, int x, int y)
{
    int i;
    for (i = 1; i <= pG->adj[x].size; ++i)
    {
    	NodePointer Header = pG->adj[x].header;
	     while (Header!= NULL)
	     {
	     	if (Header->element == y) return 1;
	         Header = Header->next;
	     }
    }
    return 0;
}

void neighbours(Graph *pG, int x)
{
    int i, n = pG->n;
    for (i = 1; i <= n; ++i)
    {
        if (adjacent(pG, x, i))
            printf("%d ", i);
    }
}

void print_graph(Graph *pG){
	int i = 1;
	for (; i <= pG->n; ++i){
		printf("Vertex %d: ", i);
		neighbours(pG, i);
		printf("\n");
	}	
}

int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, i = 1;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n, m);
    for (; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    print_graph(&G);
}
