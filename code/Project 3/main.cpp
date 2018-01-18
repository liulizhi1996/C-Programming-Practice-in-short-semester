#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int maze[30][30] = { 0 };
struct Node *stack;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve_maze(int N)
{
    struct Pos pos;
    int direction;
    pos.x = 1, pos.y = 1, direction = -1;

    push(stack, pos, direction);
    while (!is_empty(stack))
    {
        pop(stack, &pos, &direction);
        direction++;

        while (direction < 4)
        {
            if (maze[pos.x+dx[direction]][pos.y+dy[direction]] == 0)
            {
                push(stack, pos, direction);
                maze[pos.x][pos.y] = -1;
                pos.x = pos.x + dx[direction];
                pos.y = pos.y + dy[direction];
                if (pos.x == N && pos.y == N)
                {
                    printf("Path: ");
                    traverse(stack);
                    printf("(%d, %d)\n", N, N);
                    return;
                }
                else
                    direction = 0;
            }
            else
                direction++;
        }
    }

    printf("No Path!\n");
}

int main()
{
    int N;

    printf("Please enter the size of maze: ");
    scanf("%d", &N);
    for (int i = 0; i <= N+1; ++i)
    {
        maze[0][i] = 1;
        maze[N+1][i] = 1;
        maze[i][0] = 1;
        maze[i][N+1] = 1;
    }
    printf("Please enter the maze: \n");
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    init(&stack);
    solve_maze(N);
    destroy(&stack);

    return 0;
}
