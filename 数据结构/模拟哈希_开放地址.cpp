// 开放地址法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int h[N];
int n;

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N)                     // 循环
            k = 0;
    }
    return k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    memset(h, 0x3f, sizeof h);

    while (n--)
    {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I")
        {
            h[find(x)] = x;
        }
        else
        {
            if (h[find(x)] == x)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}