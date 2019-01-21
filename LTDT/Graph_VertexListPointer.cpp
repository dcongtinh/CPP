#include <stdio.h>
#include <malloc/_malloc.h>

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
    List adj[MAX_N]; //mảng các danh sách
    int n, m;
} Graph;

void MakeNullList(List *L)
{
    L->header = NULL;
    L->size = 0;
}

bool isEmpty(List *L)
{
    return (L->size);
}

Node *MakeNode(Node *P, int x)
{
    P = (Node *)malloc(sizeof(Node));
    P->element = x;
    P->next = NULL;
    return P;
}

void print_list(List *L)
{
    // NodePointer Header = L->header;
    printf("%d", L->header->element);
    // while (Header != NULL)
    // {
    //     printf("%d ", Header->element);
    //     Header = Header->next;
    // }
    // printf("\n");
}

int len(List *L)
{
    return L->size;
}

void push_back(List *L, int x)
{
    Node *P;
    P = MakeNode(P, x);

    if (L == NULL)
    {
        L->header = P;
        L->size++;
        return;
    }
    // NodePointer Header = L->header;
    // while (Header->next != NULL)
    // {
    //     Header = Header->next;
    // }
    // Header->next = P;
}

// int Retrive(List L, int k)
// {
//     int idx = 1;
//     while (L != NULL && idx != k)
//     {
//         ++idx;
//         L = L->next;
//     }
//     return L->data;
// }

// int SearchFirst(List L, int x)
// {
//     int idx = 1;
//     while (L != NULL && L->data != x)
//     {
//         ++idx;
//         L = L->next;
//     }
//     return (L != NULL ? idx : 0);
// }

// void DeleteFirst(List &L)
// {
//     L = L->next;
// }

// void DeleteKPos(List &L, int k)
// {
//     if (k == 1)
//     {
//         DeleteFirst(L);
//         return;
//     }
//     Node *P = L;
//     int idx = 1;
//     while (P != NULL && idx != k - 1)
//     {
//         P = P->next;
//         ++idx;
//     }
//     //	cout << "*" << P->data << "*" << endl;
//     P->next = P->next->next;
// }

// void Delete(List &L, int x)
// {
//     //	cout << SearchFirst(L, x);
//     //	DeleteKPos(L, 1);
//     while (SearchFirst(L, x))
//         DeleteKPos(L, SearchFirst(L, x));
// }
int main()
{
    List L;
    MakeNullList(&L);
    push_back(&L, 1);
    printf("%d", L.header->element);
    // push_back(&L, 2);
    // push_back(&L, 3);
    // print_list(&L);
}
