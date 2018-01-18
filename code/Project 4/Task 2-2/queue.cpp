#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitQueue(struct LinkQueue *Q)
{
    Q->front = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    Q->front->next = NULL;
    Q->rear = Q->front;
}

void DestroyQueue(struct LinkQueue *Q)
{
    struct QueueNode *p = Q->front, *q;

    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    Q->front = Q->rear = NULL;
}

void ClearQueue(struct LinkQueue *Q)
{
    struct QueueNode *p = Q->front->next, *q;

    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    Q->rear = Q->front;
}

int QueueEmpty(struct LinkQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}

int QueueLength(struct LinkQueue Q)
{
    struct QueueNode *p = Q.front->next;
    int len = 0;

    while (p)
    {
        ++len;
        p = p->next;
    }

    return len;
}

int GetHead(struct LinkQueue Q, int *e)
{
    if (!QueueEmpty(Q))
    {
        *e = Q.front->next->data;
        return 1;
    }
    else
        return 0;
}

void EnQueue(struct LinkQueue *Q, int e)
{
    struct QueueNode *p = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

int DeQueue(struct LinkQueue *Q, int *e)
{
    if (!QueueEmpty(*Q))
    {
        struct QueueNode *p = Q->front->next;
        Q->front->next = p->next;
        if (!p->next)
            Q->rear = Q->front;
        *e = p->data;
        free(p);
        return 1;
    }
    else
        return 0;
}

void QueueTraverse(struct LinkQueue Q)
{
    if (!QueueEmpty(Q))
    {
        struct QueueNode *p = Q.front->next;

        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    printf("\n");
}
