#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

char s[M], p[N];
int n, m;

int ne[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    return 0;
}