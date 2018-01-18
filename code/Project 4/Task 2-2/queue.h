#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
    int data;
    struct QueueNode *next;
};

struct LinkQueue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

void InitQueue(struct LinkQueue *Q);
void DestroyQueue(struct LinkQueue *Q);
void ClearQueue(struct LinkQueue *Q);
int QueueEmpty(struct LinkQueue Q);
int QueueLength(struct LinkQueue Q);
int GetHead(struct LinkQueue Q, int *e);
void EnQueue(struct LinkQueue *Q, int e);
int DeQueue(struct LinkQueue *Q, int *e);
void QueueTraverse(struct LinkQueue Q);

#endif //QUEUE_H
