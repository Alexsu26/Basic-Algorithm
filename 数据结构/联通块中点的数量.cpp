#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    int a, b;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                continue;
            cnt[find(b)] += cnt[find(a)];   // 顺序不能变，否则find(a)==find(b)
            p[find(a)] = find(b);           // 再cnt相加就变成翻倍了
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}