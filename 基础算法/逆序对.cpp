#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n;
int q[N], temp[N];

LL merge_sort(int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l + r >> 1;

    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
        {
            res += mid - i + 1;
            temp[k++] = q[j++];
        }
    }
    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    cout << merge_sort(0, n - 1) << endl;
    return 0;
}