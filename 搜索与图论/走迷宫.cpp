#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

int g[N][N];
int ck[N][N];
int n, m;

int bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    memset(ck, -1, sizeof ck);
    ck[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto c = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = c.first + dx[i];
            int y = c.second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 0 && ck[x][y] == -1)
            {
                q.push({x, y});
                ck[x][y] = ck[c.first][c.second] + 1;
            }
        }
    }
    return ck[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bfs() << endl;

    return 0;
}