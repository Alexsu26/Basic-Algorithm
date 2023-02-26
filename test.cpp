#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int n;
int h[N], hsize;
int ph[N], hp[N], cnt;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int x)
{
    int min = x;
    if (x * 2 <= cnt && h[x * 2] < h[min])
        min = x * 2;
    if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[min])
        min = x * 2 + 1;
    if (min != x)
    {
        heap_swap(min, x);
        down(min);
    }
}

void up(int x)
{
    while (x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x / 2, x);
        x /= 2;
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out","w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "I")
        {
            int x;
            cin >> x;
            h[++hsize] = x;
            ph[++cnt] = hsize;
            hp[hsize] = cnt;
            // 插入最后一个位置，忘了up
            up(hsize);
        }
        else if (s == "PM")
        {
            cout << h[1] << endl;
        }
        else if (s == "DM")
        {
            heap_swap(1, hsize);
            hsize--;
            down(1);
        }
        else if (s == "D")
        {
            int k;
            cin >> k;
            k = ph[k];
            heap_swap(k, hsize--);
            down(k);
            up(k);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k);
            up(k);
        }
    }
    for (int i = 1; i <= hsize; i++)
        cout << h[i] << " ";
    cout << "\n"
         << h[hsize];
    return 0;
}