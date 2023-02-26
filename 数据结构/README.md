# 链表
主要以数组模拟为主，而非用结构体加指针。因为C++中new操作很慢
## 单链表
应用：邻接表，存储树和图
### 定义
```C++
const int N  = 100010;
// head为头指针, e存值, ne存下个节点的下标, idx表示现在用到的下标
int head, e[N], ne[N], idx;
```
### 初始化
```C++
void init()
{
    head = -1;
    idx = 0;
}
```
### 插入到表头
```C++
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}
```
### 插到下标为k的结点后面
```C++
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}
```
### 删除下标为k的结点后面
```C++
void del(int k)
{
    ne[k] = ne[ne[k]];
}
```
## 双链表
应用： 优化某些问题
### 定义
```C++
const int N = 100010;
int e[N], l[N], r[N], idx;
```
### 初始化
```C++
// 下标0表示链表头，下标1表示链表尾
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
```
### 在下标k的结点右边插入
```C++
void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}
```
### 删除下标为k的结点
```C++
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
```
# 栈
## 基本操作
```C++
// 入栈
stk[++ top] = x;
// 出栈
-- top;
// 判断栈是否空
if (top == 0 || top == -1)  return true;
else    return false;
// 输出栈顶元素
return stk[top];
```
## 单调栈
找到一个数左边第一个的比该数小的数
```C++
// stk始终单调递增
cin >> x;
while (top && stk[top] >= x)
    -- top;
if (top)
    cout << stk[top] ;
else
    cout << "-1";
stk[++ top] = x;
```
# 队列
## 基本操作
```C++
// 入队
q[++ rear] = x;
// 出队
++ front;
// 判断队空
return front > rear;
// 输出队头
return q[front];
```
## 单调队列
滑动窗口中的最大值与最小值
```C++
// 最小值
for (int i = 0; i < n; i ++)
{
    // k为滑动窗口的大小, q维护一个单调递增的队列，存储a[]中的下标
    if (i - k + 1 > q[front])
        front ++;
    while (front <= rear && a[i] <= a[q[rear]])
        -- rear;
    q[rear] = i;
    // 前k - 1个不用输出
    if (i >= k - 1)
        cout << a[q[front]] << " ";
}
```

# KMP算法 （还需要再看看）
s[]为原数组, p[]为匹配字符串, next[]有
next[i] = j, 表示
p[1,....,j] = p[i - j + 1,....i] 

# Trie树
一种能够高效存储和查找字符串集合的数据结构（[详细定义](https://www.acwing.com/solution/content/14695/)）
```C++
int son[N][26], cnt[N], idx;
// 插入字符串
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
// 查询字符串
void query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
```

# 并查集
在近乎O(1)的时间内：
1. 将两个集合合并
2. 询问两个元素是否在同一个集合内
基本原理： 每个集合用一棵树表示，树根的编号就是整个集合的编号。每个结点存储他的父节点，p[x]表示x的父节点
问题1：如何判断树根？ if (p[x] == x)
问题2：如何求x的集合编号？ while (p[x] != x)    x = p[x];
问题3：如何合并两个集合？ p[x] = y; // x是根节点
路径压缩优化： 求x的集合编号时，将整个查询路径上的结点都直接接入根节点
```C++
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
```
# 堆 （STL可实现123）
1. 插入一个数 —— heap[++ size] = x; up(size);
2. 求集合的最小值 -- heap[1];
3. 删除最小值 -- heap[1] = heap[size --]; down(1);
4. 删除任意一个元素 -- heap[k] = heap[size --]; down(k); up(k);（只有一个会执行）
5. 修改任意一个元素 -- heap[k] = x; down(k); up(k);（只有一个会执行）
heap的两种操作：up() & down()
## 一般的堆排序
```C++
int h[N], hsize;
void down(int x)
{
    int min = x;
    if (x * 2 <= hsize && h[x * 2] < h[min])
        min = x * 2;
    if (x * 2 + 1 <= hsize && h[x * 2 + 1] < h[min])
        min = x * 2 + 1;
    if (min != x)
    {
        swap(h[min], h[x]);
        down(min);
    }
}

void up(int x)
{
    while (x / 2 && h[x / 2] < h[x])
    {
        swap(h[x / 2], h[x]);
        x /= 2;
    }
}

// 建堆，O(n)
for (int i = n / 2; i; i -- )
    down(i);

// 按序输出最小
{
    cout << h[1] << " ";
    h[1] = h[hsize--];
    down(1);
}
```
## 需要确定插入顺序
```C++
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
    if (x * 2 <= hsize && h[x * 2] < h[min])
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
    while(x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x / 2, x);
        x / = 2;
    }
}

// 插入x
{
    h[++hsize] = x;
    ph[++cnt] = hsize;
    hp[hsize] = cnt;
    up(hsize);          // 别忘了
}

// 输出最小值
{
    cout << h[1] << endl;
}

// 删除最小值
{
    heap_swap(1, hsize--);
    down(1);
}

// 删除第k个插入的数
{
    k = ph[k];
    heap_swap(k, hsize--);
    down(k);
    up(k);
}

// 修改第k个插入的数成x
{
    k = ph[k];
    h[k] = x;
    down(k);
    up(k);
}
```