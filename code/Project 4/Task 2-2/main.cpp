#include <stdio.h>
#include "queue.h"

int main()
{
    struct LinkQueue Q;
    int e;

    InitQueue(&Q);
    printf("QueueEmpty: %d\n", QueueEmpty(Q));

    printf("EnQueue 3.\n");
    EnQueue(&Q, 3);
    printf("EnQueue 5.\n");
    EnQueue(&Q, 5);
    printf("EnQueue 2.\n");
    EnQueue(&Q, 2);

    printf("Length: %d\n", QueueLength(Q));
    printf("QueueEmpty: %d\n", QueueEmpty(Q));

    DeQueue(&Q, &e);
    printf("DeQueue %d.\n", e);
    GetHead(Q, &e);
    printf("GetHead: %d.\n", e);

    printf("EnQueue 9.\n");
    EnQueue(&Q, 9);
    printf("EnQueue 4.\n");
    EnQueue(&Q, 4);
    printf("EnQueue 7.\n");
    EnQueue(&Q, 7);

    printf("QueueTraverse: ");
    QueueTraverse(Q);

    printf("ClearQueue\n");
    ClearQueue(&Q);
    if (!DeQueue(&Q, &e))
        printf("    DeQueue Error.\n");

    printf("EnQueue 11.\n");
    EnQueue(&Q, 11);
    printf("EnQueue 14.\n");
    EnQueue(&Q, 14);
    printf("EnQueue 17.\n");
    EnQueue(&Q, 17);
    printf("QueueTraverse: ");
    QueueTraverse(Q);

    DestroyQueue(&Q);

    return 0;
}
