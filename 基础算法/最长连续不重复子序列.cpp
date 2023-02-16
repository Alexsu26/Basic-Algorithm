// 给定一个长度为 n的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。
// 实际是双指针的应用
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], s[N]; //a[n]存原数组，s[N]存[j,i]之间各个数出现的次数

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;                      //每次让a[i]的数加1
        while (s[a[i]] > 1)             //若有重复
        {
            s[a[j]]--;                  //j指针后移
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}