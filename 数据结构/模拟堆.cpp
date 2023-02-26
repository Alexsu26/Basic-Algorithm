#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
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
    if (x * 2 <= hsize  && h[x * 2] < h[min])
        min = x * 2;
    if (x * 2 + 1 <= hsize && h[x * 2 + 1] < h[min])
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
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n --)
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
            up(hsize);
        }
        else if (s == "PM")
        {
            cout << h[1] << endl;
        }
        else if (s == "DM")
        {
            heap_swap(1, hsize--);
            down(1);
        }
        else if (s == "D")
        {
            int k;
            cin >> k;
            k = ph[k];
            heap_swap(k, hsize--);
            up(k), down(k);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k), down(k);
        }
    }
    return 0;
}
