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
