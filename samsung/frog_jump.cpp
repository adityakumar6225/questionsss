#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

int n, sX, sY, tX, tY;
int mat[105][105], dis[105][105], vis[105][105];

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void calculateFrogJump() {
    queue<Point> q;
    q.push({sX, sY});

    vis[sX][sY] = 1;
    dis[sX][sY] = 0;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = p.x + dirX[i];
            int newY = p.y + dirY[i];

            if (isValid(newX, newY) && mat[newX][newY] == 1 && vis[newX][newY] == 0) {
                /* Horizontal Cost */
                if (i == 0 || i == 2) {
                    dis[newX][newY] = dis[p.x][p.y];
                } else if (i == 1 || i == 3) {
                    dis[newX][newY] = 1 + dis[p.x][p.y];
                }

                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
    cout << dis[tX][tY];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            vis[i][j] = 0;
            dis[i][j] = 0;
        }
    }

    cin >> sX >> sY >> tX >> tY;

    calculateFrogJump();
    return 0;
}
