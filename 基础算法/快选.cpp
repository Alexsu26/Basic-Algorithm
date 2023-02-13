#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quick_sort(int q[], int l, int r, int k)
{
    if (l == r)
        return q[l];
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    if (k <= j)
        return quick_sort(q, 0, j, k);
    else
    {
        return quick_sort(q, j + 1, r, k - j);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    cout << quick_sort(q, 0, n - 1, k);
    return 0;
}