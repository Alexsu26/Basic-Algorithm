#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];
int d[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        cin >> v[i] >> w[i];
    
    // 二维状态
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;

    // 一维状态
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- )
            d[j] = max(d[j], d[j - v[i]] + w[i]);
    cout << d[m] << endl;
    return 0;
}