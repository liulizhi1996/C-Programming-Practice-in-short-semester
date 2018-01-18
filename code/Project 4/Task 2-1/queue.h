#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 5

struct SqQueue
{
    int *data;
    int front;
    int rear;
};

void InitQueue(struct SqQueue *Q);
void DestroyQueue(struct SqQueue *Q);
void ClearQueue(struct SqQueue *Q);
int QueueEmpty(struct SqQueue Q);
int QueueLength(struct SqQueue Q);
int GetHead(struct SqQueue Q, int *e);
int EnQueue(struct SqQueue *Q, int e);
int DeQueue(struct SqQueue *Q, int *e);
void QueueTraverse(struct SqQueue Q);

#endif //QUEUE_H
