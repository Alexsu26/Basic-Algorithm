#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int N = 300010;
int a[N];
int s[N];
vector<int> alls;
vector<pair<int, int>> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        alls.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i++)
        cout << a[i] << " ";

    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}