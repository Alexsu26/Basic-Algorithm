#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, m;

struct Edge
{
    int a, b, w;
    bool operator < (const Edge &M)const{
        return w < M.w;
    }
}edges[N];

int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    // 初始化并查集
    for (int i = 0; i < n; i ++ )
        p[i] = i;

    for (int i = 0; i <= m; i ++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            cnt ++;
            res += w;
        }
    }

    if (cnt < n - 1)
        cout << "impossible" << endl;
    else
    {
        cout << res << endl;
    }
    
    return 0;
}
