#include <iostream>

using namespace std;

const int N = 20;
char path[N][N];
bool col[N], row[N], dg[N], udg[N];
int n;

void dfs(int x, int y, int sum)
{
    if (sum > n)
        return;
    if (y == n)
    {
        y = 0;
        x++;
    }
    if (x == n)
    {
        if (sum == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << path[i][j];
                cout << endl;
            }
        }
        return ;            // 不管是否满足，都要return
    }
    
    // 不填
    dfs(x, y + 1, sum);
    
    // 填
    if (!row[x] && !col[y] && !dg[x + y] && !udg[y - x + n])
    {
        path[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = true;
        dfs(x, y + 1, sum + 1);
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = false;
        path[x][y] = '.';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n;i ++ )
        for (int j = 0; j < n; j ++)
            path[i][j] = '.';
    
    dfs(0, 0, 0);

    return 0;
}