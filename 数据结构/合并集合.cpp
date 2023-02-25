#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

int find(int x)             // 查找根节点
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
    for (int i = 1; i <= n; i ++)
        p[i] = i;
    char op[2];
    int a, b;
    while (m --)
    {
        cin >> op >> a >> b;
        if (op[0] == 'M')
        {
            p[find(a)] = find(b);
        }
        else
        {
            if (find(a) == find(b))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
