#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a]; 
    h[a] = idx ++;
}

bool toposort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[++ tt] = i;
    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --;
            if (d[j] == 0)
                q[++ tt] = j;
        }
    }
    return tt == n - 1;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --)
    {
        int a, b;
        cin >> a >> b;
        add (a, b);
        d[b] ++;
    }
    if (toposort())
    {
        for (int i = 0; i < n; i ++)
            cout << q[i] <<  " " ;
        cout << endl; 
    }
    else
    {
        cout << "-1" << endl;
    }
    
    return 0;
}
