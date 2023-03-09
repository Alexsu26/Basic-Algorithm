#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e5 + 10;
int n, m, k;
struct Edge
{
    int a, b, w;
}edges[M];
int dist[N], backup[N];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i ++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++)
        {
            auto t = edges[j];
            dist[t.b] = min(dist[t.b], backup[t.a] + t.w);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
    return 0;
}
