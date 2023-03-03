#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int n;

int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];
int res = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dfs(int u)
{
    st[u] = true;
    int sum = 0, size = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int k = dfs(j);
            sum += k;
            size = max(size, k);
        }
    }
    size = max(size, n - sum - 1);
    res = min(size, res);

    return sum + 1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << res << endl;
    
    return 0;
}
