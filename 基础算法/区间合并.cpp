#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
const int N = 1e5 + 10;
vector<pair<int, int>> segs;

void merge(vector<pair<int, int>> &segs)
{
    vector<pair<int, int>> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            if (st != -2e9)
                res.push_back(item);
            st = item.first;
            ed = item.second;
        }
        else
            ed = max(ed, item.second);
    }
    res.push_back({st, ed});            //添加最后一个！
    segs = res;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}