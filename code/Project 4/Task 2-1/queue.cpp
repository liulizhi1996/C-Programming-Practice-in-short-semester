#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitQueue(struct SqQueue *Q)
{
    Q->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    Q->front = Q->rear = 0;
}

void DestroyQueue(struct SqQueue *Q)
{
    free(Q->data);
    Q->front = Q->rear = 0;
}

void ClearQueue(struct SqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int QueueEmpty(struct SqQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}

int QueueLength(struct SqQueue Q)
{
    return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

int GetHead(struct SqQueue Q, int *e)
{
    if (!QueueEmpty(Q))
    {
        *e = Q.data[Q.front];
        return 1;
    }
    else
        return 0;
}

int EnQueue(struct SqQueue *Q, int e)
{
    if ((Q->rear + 1) % MAX_SIZE == Q->front)
        return 0;
    else
    {
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear + 1) % MAX_SIZE;
        return 1;
    }
}

int DeQueue(struct SqQueue *Q, int *e)
{
    if (QueueEmpty(*Q))
        return 0;
    else
    {
        *e = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAX_SIZE;
        return 1;
    }
}

void QueueTraverse(struct SqQueue Q)
{
    for (int i = Q.front; i != Q.rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", Q.data[i]);
    }
    printf("\n");
}
