#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            // 父亲是2儿子就染1， 父亲是1儿子就染2，因此传入3 - c
            if (!dfs(j, 3 - c))
                return false;
        }
        else
        {
            if (color[j] == c)
                return false;
        }
    }
    return true;
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
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++)
    {
        if (!color[i])
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
    }
    if (flag)
        cout << "Yes" << endl;
    else
    {
        
        cout << "No" << endl;
    }
    
    return 0;
}
