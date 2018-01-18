#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(struct Node **head)
{
    *head = (struct Node *)malloc(sizeof(struct Node));
    (*head)->next = NULL;
}

void destroy(struct Node **head)
{
    struct Node *p, *q;

    p = *head;
    if (*head)
        q = (*head)->next;
    while (p)
    {
        free(p);
        p = q;
        if (q)
            q = q->next;
    }
    *head = NULL;
}

void clear(struct Node *head)
{
    struct Node *p, *q;

    if (head)
    {
        destroy(&(head->next));
        head->next = NULL;
    }
}

int is_empty(struct Node *head)
{
    if (head && head->next)
        return 0;
    else
        return 1;
}

int top(struct Node *head, struct Pos *pos, int *direction)
{
    if (!is_empty(head))
    {
        pos->x = head->next->pos.x;
        pos->y = head->next->pos.y;
        *direction = head->next->direction;
        return 1;
    }
    else
        return 0;
}

void push(struct Node *head, struct Pos pos, int direction)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->pos.x = pos.x;
    p->pos.y = pos.y;
    p->direction = direction;
    p->next = head->next;
    head->next = p;
}

int pop(struct Node *head, struct Pos *pos, int *direction)
{
    if (!is_empty(head))
    {
        struct Node *p = head->next;
        pos->x = p->pos.x;
        pos->y = p->pos.y;
        *direction = p->direction;
        head->next = p->next;
        free(p);
        return 1;
    }
    else
        return 0;
}

void recursive_traverse(struct Node *p)
{
    if (p)
    {
        recursive_traverse(p->next);
        printf("(%d, %d)->", p->pos.x, p->pos.y);
    }
}

void traverse(struct Node *head)
{
    if (!is_empty(head))
    {
        recursive_traverse(head->next);
    }
}
