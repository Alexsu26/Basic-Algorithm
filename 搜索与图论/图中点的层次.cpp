#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[2 * N], ne[2 * N], idx;
int d[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs()
{
    memset(d, -1, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int k = q.front();
        q.pop();
        for (int i = h[k]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                q.push(j);
                d[j] = d[k] + 1;
            }
        }
    }
    return d[n];
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
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}
