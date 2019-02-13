#include <bits/stdc++.h>

int n = 100000;

typedef int keyType;
typedef float otherType;
typedef struct RecordType
{
    keyType key;
    otherType otherFields;
} RecordType;

void swap(RecordType *x, RecordType *y)
{
    RecordType tmp = *x;
    *x = *y;
    *y = tmp;
}

void read(RecordType *a)
{
    int i = 1;
    scanf("%d", &n);
    for (; i <= n; ++i)
    {
        scanf("%d%f", &a[i].key, &a[i].otherFields);
    }
}

void print(RecordType *a)
{
    int i = 1;
    for (; i <= n; ++i)
        printf("%d %.2f\n", a[i].key, a[i].otherFields);
}

void SelectSort(RecordType *a)
{
    int i = 1, j, lowIdx;
    for (; i < n; ++i)
    {
        keyType lowKey = a[i].key;
        for (j = i + 1; j <= n; ++j)
        {
            if (a[j].key < lowKey)
            {
                lowKey = a[j].key;
                lowIdx = j;
            }
        }
        swap(&a[i], &a[lowIdx]);
    }
}

void InsertionSort(RecordType *a)
{
    int i = 2, j;
    for (; i <= n; ++i)
    {
        j = i;
        while (j > 1 && a[j].key < a[j - 1].key)
        {
            swap(&a[j], &a[j - 1]);
            --j;
        }
    }
}

void BubbleSort(RecordType *a)
{
    int i = 1, j;
    for (; i < n; ++i)
    {
        for (j = i + 1; j <= n; ++j)
        {
            if (a[i].key > a[j].key)
                swap(&a[i], &a[j]);
        }
    }
}

void QuickSort(RecordType *a, int l, int r)
{
    int i = l, j = r, m = (l + r) / 2;
    keyType pivot = a[m].key;
    while (i <= j)
    {
        while (a[i].key < pivot)
            ++i;
        while (a[j].key > pivot)
            --j;
        if (i <= j)
        {
            swap(&a[i++], &a[j--]);
        }
    }
    if (l < j)
        QuickSort(a, l, j);
    if (r > i)
        QuickSort(a, i, r);
}

// int partition(RecordType *a, int l, int r)
// {
//     int k = a[r - 1].key;
//     int p = l - 1, i;
//     for (i = l; i < r; ++i)
//         if (k > a[i].key)
//             swap(&a[i], &a[++p]);
//     swap(&a[r - 1], &a[p + 1]);
//     return p + 1;
// }

// void QuickSort(RecordType *a, int l, int r)
// {
//     if (l >= r)
//         return;
//     int p = partition(a, l, r);
//     QuickSort(a, l, p);
//     QuickSort(a, p + 1, r);
// }

int main()
{
    // freopen("input.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
    // printf("%d\n", n);
    // int i = 1;
    // for (; i <= n; ++i)
    // {
    //     printf("%d %.2f\n", rand() % 1000, (float)rand() / (float)rand());
    // }
    // return 0;
    // freopen("input.txt", "w", stdout);
    RecordType a[100006];
    read(a);
    // BubbleSort(a);
    // SelectSort(a);
    // InsertionSort(a);
    QuickSort(a, 1, n);
    print(a);
}