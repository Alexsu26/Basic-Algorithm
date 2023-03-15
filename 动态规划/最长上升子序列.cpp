#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
int a[N], f[N];
int g[N];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        g[i] = 0;
        for (int j = 1; j < i; j ++)
            if (a[j] < a[i])
            {
                if (f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }
    }
    
    int res = 1;
    for (int i = 2; i <= n; i ++)
        if (f[i] > f[res])
            res = i;
    cout << f[res] << endl;

    // 倒序打印输出子序列
    for (int i = 0, len = f[res]; i < len; i ++)
    {
        cout << a[res] << " " ;
        res = g[res];
    }
    return 0;
}
