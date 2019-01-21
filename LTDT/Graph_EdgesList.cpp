#include <bits/stdc++.h>

using namespace std;

#define MAX_M 500

struct Edge
{
    int u, v;
    Edge(int _u, int _v)
    {
        u = _u;
        v = _v;
    }
    Edge()
    {
        u = v = 0;
    }
    bool operator==(Edge e)
    {
        return (e.u == u && e.v == v);
    }
    void operator=(Edge e)
    {
        u = e.u;
        v = e.v;
    }
    void print()
    {
        printf("%d %d\n", u, v);
    }
};

// typedef Edge EdgeStruct;

struct Graph
{
    Edge edges[MAX_M];
    int n, m;
    Graph()
    {
        n = m = 0;
    }
};

void init_graph(Graph *pG, int n)
{
    pG->n = n, pG->m = 0;
}

void print_graph(Graph G)
{
    int n = G.n, m = G.m;
    printf("%d %d\n", n, m);
    for (int i = 0; i < m; ++i)
    {
        G.edges[i].print();
    }
}

void add_edge(Graph *pG, int u, int v)
{
    Edge e(u, v);
    pG->edges[pG->m++] = e;
}

int degree(Graph G, int u)
{
    int cnt = 0;
    for (int i = 0; i < G.m; ++i)
        cnt += (G.edges[i].u == u || G.edges[i].v == u);
    return cnt;
}

int adjacent(Graph *G, int u, int v) ///u adjacent v
{
    for (int i = 0; i < G->m; ++i)
    {
        Edge e(u, v), re(v, u);
        if (G->edges[i] == e || G->edges[i] == re)
            return 1;
    }
    return 0;
}

void neighbours(Graph *G, int x)
{
    for (int i = 1; i <= G->n; ++i)
    {
        if (adjacent(G, x, i))
            printf("%d ", i);
    }
}
int main()
{
    Graph G;
    int n, m;
    cin >> n >> m;
    init_graph(&G, n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        add_edge(&G, u, v);
    }

    print_graph(G);
}