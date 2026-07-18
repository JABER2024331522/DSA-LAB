#include <stdio.h>
#include <stdlib.h>

typedef struct CQueue
{
    int *arr;
    int front;
    int rear;
    int cnt;
    int size;
} CQueue;

CQueue *create(int s)
{
    CQueue *CQ = (CQueue *)malloc(sizeof(CQueue));
    if (!CQ) return NULL;

    CQ->arr = (int *)malloc(s * sizeof(int));
    if (!CQ->arr)
    {
        free(CQ);
        return NULL;
    }

    CQ->front = 0;
    CQ->rear = -1;
    CQ->cnt = 0;
    CQ->size = s;
    return CQ;
}

int enqueue(CQueue *CQ, int v)
{
    if (CQ->cnt == CQ->size)
        return 0; // full

    CQ->rear = (CQ->rear + 1) % CQ->size;
    CQ->arr[CQ->rear] = v;
    CQ->cnt++;
    return 1;
}

int dequeue(CQueue *CQ, int *out)
{
    if (CQ->cnt == 0)
        return 0; // empty

    *out = CQ->arr[CQ->front];
    CQ->front = (CQ->front + 1) % CQ->size;
    CQ->cnt--;
    return 1;
}

int front(CQueue *CQ, int *out)
{
    if (CQ->cnt == 0)
        return 0;
    *out = CQ->arr[CQ->front];
    return 1;
}

static inline int size(CQueue *CQ)
{
    return CQ->cnt;
}

static inline int isEmpty(CQueue *CQ)
{
    return CQ->cnt == 0;
}

void display(CQueue *CQ)
{
    if (CQ->cnt == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("CQueue: ");
    for (int i = 0, idx = CQ->front; i < CQ->cnt; i++, idx = (idx + 1) % CQ->size)
        printf("%d -> ", CQ->arr[idx]);
    printf("NULL\n");
}

void free_CQ(CQueue **CQ)
{
    if (CQ && *CQ)
    {
        free((*CQ)->arr);
        free(*CQ);
        *CQ = NULL;
    }
}

int main()
{
    CQueue *CQ = create(5);
    if (!CQ) return 1;

    enqueue(CQ, 10);
    enqueue(CQ, 20);
    enqueue(CQ, 30);
    enqueue(CQ, 40);

    int val;
    if (dequeue(CQ, &val)) printf("dequeued: %d\n", val);
    if (dequeue(CQ, &val)) printf("dequeued: %d\n", val);

    enqueue(CQ, 50);
    enqueue(CQ, 60);

    display(CQ);
    printf("Size: %d\n", size(CQ));

    free_CQ(&CQ);
    return 0;
}