#include <iostream>
#include <queue>
#include <map>
#include <stack>

#define MAX_SIZE 30

using namespace std;

class Point
{
public:
    int x;
    int y;

public:
    Point()
    { }

    Point(int a, int b)
    {
        x = a, y = b;
    }

    bool operator <(const Point &pos) const
    {
        if (x < pos.x)
            return true;
        else if (x == pos.x)
        {
            if (y < pos.y)
                return true;
        }
        return false;
    }

    bool operator ==(const Point &pos) const
    {
        return x == pos.x && y == pos.y;
    }

    bool operator !=(const Point &pos) const
    {
        return x != pos.x || y != pos.y;
    }
};

int maze[MAX_SIZE][MAX_SIZE] = { 0 };
queue<Point> open_table;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print_path(map<Point, Point> come_from, int N)
{
    Point pos = Point(N, N);
    stack<Point> path;

    while (pos != Point(1, 1))
    {
        path.push(pos);
        pos = come_from[pos];
    }

    cout << "(1, 1)";
    while (!path.empty())
    {
        pos = path.top();
        cout << "->(" << pos.x << ", " << pos.y << ")";
        path.pop();
    }
    cout << endl;
}

void solve_maze(int N)
{
    map<Point, Point> come_from;

    open_table.push(Point(1, 1));

    while (!open_table.empty())
    {
        Point pos = open_table.front();
        open_table.pop();
        maze[pos.x][pos.y] = -1;

        if (pos.x == N && pos.y == N)
        {
            printf("Path: ");
            print_path(come_from, N);
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            Point new_pos = Point(pos.x+dx[i], pos.y+dy[i]);
            if (new_pos.x < 1 || new_pos.x > N || new_pos.y < 1 || new_pos.y > N || maze[new_pos.x][new_pos.y] != 0)
                continue;
            open_table.push(new_pos);
            come_from[new_pos] = pos;
        }
    }

    cout << "No path!" << endl;
}

int main()
{
    int N;

    cout << "Please enter the size of maze: ";
    cin >> N;

    cout << "Please enter the maze: " << endl;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i <= N+1; ++i)
    {
        maze[0][i] = maze[N+1][i] = maze[i][0] = maze[i][N+1] = 1;
    }

    solve_maze(N);

    return 0;
}
