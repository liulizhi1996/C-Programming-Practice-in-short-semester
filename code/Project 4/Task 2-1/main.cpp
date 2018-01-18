#include <stdio.h>
#include "queue.h"

int main()
{
    struct SqQueue Q;
    int e;

    InitQueue(&Q);
    printf("QueueEmpty: %d\n", QueueEmpty(Q));

    printf("EnQueue 3.\n");
    if (!EnQueue(&Q, 3))
        printf("    EnQueue 3. Error!\n");
    printf("EnQueue 5.\n");
    if (!EnQueue(&Q, 5))
        printf("    EnQueue 5. Error!\n");
    printf("EnQueue 2.\n");
    if (!EnQueue(&Q, 2))
        printf("    EnQueue 2. Error!\n");

    printf("Length: %d\n", QueueLength(Q));
    printf("QueueEmpty: %d\n", QueueEmpty(Q));

    DeQueue(&Q, &e);
    printf("DeQueue %d.\n", e);
    GetHead(Q, &e);
    printf("GetHead: %d.\n", e);

    printf("EnQueue 9.\n");
    if (!EnQueue(&Q, 9))
        printf("    EnQueue 9. Error!\n");
    printf("EnQueue 4.\n");
    if (!EnQueue(&Q, 4))
        printf("    EnQueue 4. Error!\n");
    printf("EnQueue 7.\n");
    if (!EnQueue(&Q, 7))
        printf("    EnQueue 7. Error!\n");

    printf("QueueTraverse: ");
    QueueTraverse(Q);

    printf("ClearQueue\n");
    ClearQueue(&Q);
    if (!DeQueue(&Q, &e))
        printf("    DeQueue Error.\n");

    printf("EnQueue 11.\n");
    if (!EnQueue(&Q, 11))
        printf("    EnQueue 11. Error!\n");
    printf("EnQueue 14.\n");
    if (!EnQueue(&Q, 14))
        printf("    EnQueue 14. Error!\n");
    printf("EnQueue 17.\n");
    if (!EnQueue(&Q, 17))
        printf("    EnQueue 17. Error!\n");
    printf("QueueTraverse: ");
    QueueTraverse(Q);

    DestroyQueue(&Q);

    return 0;
}
