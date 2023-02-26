#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], hsize;

void down(int x)
{
    int min = x;
    if (2 * x <= hsize && h[2 * x] < h[min])
        min = 2 * x;
    if (2 * x + 1 <= hsize && h[2 * x + 1] < h[min])
        min = 2 * x + 1;
    if (min != x)
    {
        swap(h[min], h[x]);
        down(min);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        cin >> h[i];
    hsize = n;

    // 建堆
    for (int i = n / 2; i; i -- )
        down(i);

    while (m -- )
    {
        cout << h[1] << " ";
        h[1] = h[hsize --];
        down(1);
    }
    return 0;
}
