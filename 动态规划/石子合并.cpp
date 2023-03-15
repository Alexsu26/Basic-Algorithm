#include <iostream>

using namespace std;

const int N = 310;
int n, m;
int a[N], s[N];
int f[N][N];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int len = 2; len <= n; len ++)
        for (int i = 1; i + len - 1 <= n; i ++)
        {
            int j = i + len - 1;
            f[i][j] = 1e9;
            for (int k = i; k < j; k ++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    
    cout << f[1][n] << endl;
    return 0;
}