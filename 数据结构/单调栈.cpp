#include <iostream>

using namespace std;

const int N = 100010;
int n;
int stk[N], tt;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        while (tt & stk[tt] >= x)
            tt--;
        if (tt)
            printf("%d ", stk[tt]);
        else
            printf("-1 ");
        stk[++tt] = x;
    }
    return 0;
}