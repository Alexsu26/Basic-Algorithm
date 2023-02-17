#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int N = 300010;                           // 插入和查询总大小
int a[N];                                       // 存储离散化后各坐标的值
int s[N];                                       // a的前缀和，方便计算
vector<int> alls;                               // 涉及的所有坐标，包括插入和查询
vector<pair<int, int>> add, query;              // 暂存插入和查询的输入

int find(int x)                                 // 找到离散化后的位置，最后+1是为了让a从1开始存储，便于前缀和计算
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
    // 去重，可以记住
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 计算前缀和
    for (int i = 1; i <= alls.size(); i++)
        cout << a[i] << " ";

    // 查询，这里i <= alls.size(),因为只需计算到访问过的坐标即可；
    // 若i <= a.size(),则a.size() > alls.size()的部分全为0，无意义
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    // 查询并输出
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}