#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], idx;

int n;
char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        char op[2];                         // 可以过滤掉行末的空格
        cin >> op >> str;
        if (op[0] == 'I')
            insert(str);
        else
            cout << query(str) << endl;
    }
}