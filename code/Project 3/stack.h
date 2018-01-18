#ifndef STACK_H
#define STACK_H

struct Pos
{
    int x;
    int y;
};

struct Node
{
    struct Pos pos;
    int direction;
    struct Node *next;
};

void init(struct Node **head);
void destroy(struct Node **head);
void clear(struct Node *head);
int is_empty(struct Node *head);
int top(struct Node *head, struct Pos *pos, int *direction);
void push(struct Node *head, struct Pos pos, int direction);
int pop(struct Node *head, struct Pos *pos, int *direction);
void traverse(struct Node *head);

#endif //STACK_H
