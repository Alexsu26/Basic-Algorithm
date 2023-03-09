#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N];
int d[N];
bool st[N];

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || d[j] < d[t]))
                t = j;
        for (int j = 1; j <= n; j ++ )
            d[j] = min(d[j], d[t] + g[t][j]);
        st[t] = true;
    }
    if (d[n] == 0x3f3f3f3f)
        return -1;
    else
        return d[n];
}


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
    return 0;
}