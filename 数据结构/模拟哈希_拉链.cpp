// 拉链法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

int n;

void insert(int x)
{
    int k = ((x % N) + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

bool find(int x)
{
    bool flag = false;
    int k = ((x % N) + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
            flag = true;
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    memset(h, -1, sizeof h);
    while (n--)
    {
        string s;
        int x;
        cin >> s >> x;
        if (s == "I")
            insert(x);
        else
        {
            if (find(x))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}