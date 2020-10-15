#include <stdio.h>
#define maxN 100
#define oo 1e9

int trace[maxN], delta[maxN], f[maxN][maxN], s, t;
int queue[maxN], front, rear;

int min(int a, int b) { return a > b ? b : a; }
void push(int x) { queue[++rear] = x; }
int pop() { return queue[++front]; }
int empty() { return front >= rear; }

typedef struct
{
    int n, m;
    int a[maxN][maxN];
} Graph;

void init_graph(Graph *pG, int n, int m)
{
    pG->n = n;
    pG->m = m;
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            pG->a[i][j] = 0;
    }
}

void add_edge(Graph *pG, int u, int v, int c)
{
    pG->a[u][v] = c;
}

int adjacent(Graph *pG, int u, int v)
{
    return pG->a[u][v];
}

int findPath(Graph *pG)
{
    int n = pG->n, u, v;
    for (u = 1; u <= n; ++u)
        trace[u] = 0;
    trace[s] = s;
    delta[s] = oo;
    push(s);
    while (!empty())
    {
        u = pop();
        for (v = 1; v <= n; ++v)
        {
            if (adjacent(pG, u, v) && !trace[v])
            {
                if (pG->a[u][v] > f[u][v])
                {
                    trace[v] = u;
                    delta[v] = min(delta[u], pG->a[u][v] - f[u][v]);
                    push(v);
                }
                else if (f[v][u] > 0)
                {
                    trace[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    push(v);
                }
            }
        }
    }
    return trace[t];
}

void Incflow()
{
    int v = t;
    while (v != s)
    {
        int u = trace[v];
        if (u)
            f[u][v] += delta[t];
        else
        {
            u = -u;
            f[v][u] -= delta[t];
        }
        v = u;
    }
}

int main()
{
    int n, m, i;
    Graph G;
    scanf("%d%d", &n, &m);
    s = 1;
    t = n;
    init_graph(&G, n, m);
    for (i = 1; i <= m; ++i)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add_edge(&G, u, v, c);
    }
    while (findPath(&G))
        Incflow();
    int ans = 0;
    for (i = 1; i <= n; ++i)
        ans += f[i][t];
    printf("%d", ans);

    return 0;
}