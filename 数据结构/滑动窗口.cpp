#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];
int front, rear;
int n, k;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    front = 0, rear = -1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        if (i - k + 1 > q[front])
            front++;
        while (front <= rear && a[i] <= a[q[rear]])
            --rear;
        q[++rear] = i;
        if (i >= k - 1)
            cout << a[q[front]] << " ";
    }
    cout << endl;

    front = 0, rear = -1;
    for (int i = 0; i < n; i++)
    {
        if (i - k + 1 > q[front])
            front++;
        while (front <= rear && a[i] >= a[q[rear]])
            --rear;
        q[++rear] = i;
        if (i >= k - 1)
            cout << a[q[front]] << " ";
    }
    cout << endl;
    return 0;
}
