# 快速排序
```C++
void quick_sort(int q[], int l, int r)
{
    //
    if( l >= r ) return;

    //
    int x = q[ ( l + r ) /2 ];
    int i = l - 1, j = r + 1;
    while( i < j )
    {
        do i++; while( q[i] < x );
        do j--; while( q[j] > x );
        if( i < j ) swap( q[i], q[j] );
    }

    //
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}
```

# 归并排序
```C++
void merge_sort(int q[], int l, int r)
{
    if( l >= r ) return;
    int mid = ( l + r ) / 2;

    merge_sort(q, l, mid);
    merge_sort(q,mid+1,r);

    int k = 0, i = l, j = mid + 1;
    while( i <= mid && j <= r )
    {
        if( q[i] <= q[j] )  temp[k++] = q[i++]; //要开辟额外的辅助空间
        else    temp[k++] = q[j++];
    }
    while( i <= mid )   temp[k++] = q[i++];
    while( j<= r )  temp[k++] = q[j++];
    for(i=l,k=0; i<=r; i++,k++)
        q[i] = temp[k];  
}
```

# 二分查找
## 整数二分
```C++
//l = mid,则mid加1
int l = 0, r = n - 1;
while( l < r )
{
    int mid = ( l + r + 1 ) / 2;
    if( q[mid] <= x )   l = mid;
    else    r = mid - 1;
}
//r = mid,无须加1
while( l < r )
{
    int mid = ( l + r ) / 2;
    if( q[mid] >= x )   r = mid;
    else    l = mid + 1;
}
```
## 浮点二分
```C++
double l = -Max, r = Max;
while( r - l > 1e-8 )
{
    double mid = q[( l + r ) / 2];
    if( mid * mid <=  x )  l = mid;
    else    r = mid;
}
```
> · 上下界取值必须涵盖x的取值范围，不能单纯地取[-x,x]，如-0.001的立方根比本身还大
· 循环条件为r-l>1e-8,具体的精度按照题目给定小2
· 无须考虑mid和边界取值

# 高精度运算
## 读入
```C++
string s;   //读入大整数
vector<int> A;  //存储大整数，低位放前面，高位放后面
for (int i = s.size() - 1; i >= 0; i -- )
    A.push_back(s[i] - '0');    //char -> int
```
## 输出
```C++
auto C = add(A, B);
for (int i = C.size() - 1; i >= 0; i -- )
    printf("%d", C[i]);
```
## 加法
```C++
vector<int> add (vector<int> &A, vector<int> &B)
{
    vector<int> C;      //存储结果
    int t = 0;          //进位
    for (int i = 0; i < A.size() || i < B.size(); i ++ )
    {
        if (i < A.size())   t += A[i];
        if (i < B.size())   t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)  C.push_back(1);     //如果最高位有进位，则再添1
    return C;
}
```
## 减法
```C++
// 定义一个cmp函数，判断A与B的大小关系，视情况输出负号
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())   return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i -- )           //从最高位开始往下比
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;            //若每一位都相同，则返回true，不需要负号
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i <A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size())   t -= B[i];
        C.push_back((t + 10) % 10);    //无论t正负，+10再%10都能取到个位
        if (t < 0)      //t为借位标志
            t = 1;
        else
            t = 0;
    }
}
```
## 乘法
```C++
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    for (int i = 0, t = 0; i <A.size() || t; i ++ )      //将最后t>0的情况也包含
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();       //去除前导0
    return C;
}
```
## 除法
```C++
vector<int> div(vector<int> &A, int b, int &r)  //r表示余数
{
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());        //从高位开始存储，所以反转一下
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
```

# 前缀和
> 数组A:[a1,a2,a3...,an],若有数组B满足
    bi = a1 + a2 + a3 + ... + ai
    则称B为A的前缀和
    有b[i] = b[i -1] + a[i]
    其作用在于可以在O(1)时间内计算A数组中下标[l,r]的和
## 一维
```C++
//构造
for (int i = 1; i <= n; i ++ )       //下标从1开始，b[0]默认为0; n为a的长度
    b[i] = b[i - 1] + a[i];
//计算
cout << b[r] - b[l - 1] << endl;
```
## 二维
```C++
//构造
for (int i = 1; i<= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];

//计算
printf("%d", b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1]);
```
# 差分
> 数组A:[a1,a2,a3...,an],若有数组B满足
    b1 + b2 + b3 + ... + bi = ai
    则称B为A的差分数组
    其作用在于可以在O(1)时间内将A数组中下标[l,r]的元素都加C
    实际上只需考虑insert函数，构造可视为在[l,l]上加a[i,j]
## 一维
```C++
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
//构造
for (int i = 1; i <= n; i ++ )
    insert(i, i, a[i]);
//计算
insert(l, r, c);
//输出，输出的是原数组，而非差分数组
for (int i = 1; i <= n; i ++ )
    b[i] += b[i - 1];
cout << b[i] << " ";
```
## 二维
```C++
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
//构造
for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
    {
        int x;
        cin >> x;
        insert(i, j, i, j, x);  //不能直接cin >> b[i][j]; insert(i,j,i,j,b[i][j])，会导致b[i][j] -> 2b[i][j]
    }
//计算
insert(x1, y1, x2, y2, c);
//输出
for (int i = 1; i <= n; i ++ )
{
    for (int j = 1; j <= m; j ++ )
    {
        b[i][j] = b[i - 1][j] + b[i][j - 1] -b[i-1][j-1] + b[i][j];
        cout << b[i][j]  << " ";
    }
    cout << endl;
}
    
```

# 双指针
## 作用
优化暴力算法
```C++
// 暴力,时间复杂度O(n^2)
for (int i = 0; i < n; i ++ )
    for (int j = 0; j < n; j ++ )
        check 

// 双指针，时间复杂度O(n),要求i，j是单调的
for (int i = 0; i < n; i ++ )
{
    while ( j <= i && check(j, i))
        j ++;
    //下面按具体题目写
}
```

# 位运算
## 求二进制表示中的第k位(低位为第0位)
```C++
int n = 10;
for (int k = 3; k >= 0; k -- )
    cout << ( n >> k & 1);
```
## lowbit(),求二进制表示中有几个1
返回二进制的表示中最后一个1的位置，也是二进制表示
> 例如n = 10 = (1010)2, lowbit(n) = 10
```C++
int lowbit(int n)
{
    return n & -n;
}
```

# 离散化
满足整个值域很大，但是用到的很少就可以使用离散化。见区间和例题

# 区间合并
1. 将所有区间左端点排序
2. 对当前区间[start,end], 后面第i个区间与其关系为：
    · 包含，则不更新；
    · 相交，则end更新为i区间的end
    · 相离，则当前区间为一个区间，[start,end]更新为i区间
