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
1. 插入一个数 —— $heap[++ size] = x; up(size);$  
2. 求集合的最小值 -- $heap[1];$  
3. 删除最小值 -- $heap[1] = heap[size --]; down(1);$  
4. 删除任意一个元素 -- $heap[k] = heap[size --]; down(k); up(k);$ （只有一个会执行）   
5. 修改任意一个元素 -- $heap[k] = x; down(k); up(k);$（只有一个会执行）   
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

# 哈希表
一般只有添加和查找两个操作
## 拉链法
```C++
// N为大于数值的最小质数
const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}
```

## 开放地址法
```C++
// N取大于二倍数值的最小质数
const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k ++;
        if (k == N)
            k = 0;
    }
    return k;
}

```
> 关于null为什么取0x3f3f3f3f:
> 我们常常需要用到设置一个常量用来代表“无穷大”。
    比如对于int类型的数，有的人会采用INT_MAX，即0x7fffffff作为无穷大。但是以INT_MAX为无穷大常常面临一个问题，即加一个其他的数会溢出。
    而这种情况在动态规划，或者其他一些递推的算法中常常出现，很有可能导致算法出问题。
所以在算法竞赛中，我们常采用0x3f3f3f3f来作为无穷大。0x3f3f3f3f主要有如下好处：
0x3f3f3f3f的十进制为1061109567，和INT_MAX一个数量级，即 $10^9$ 数量级，而一般场合下的数据都是小于 $10^9$ 的。
0x3f3f3f3f * 2 = 2122219134，无穷大相加依然不会溢出。

> 关于memset：
可以使用memset(array, 0x3f, sizeof(array))来为数组设初值为0x3f3f3f3f
因为memset按照字节赋值，而int型占4字节，因此每个字节赋值为0x3f，每个值就为0x3f3f3f3f。
同理，memset常用于赋值为0 (0x00)和-1 (0xff)

## 字符串前缀哈希
把字符串变成一个p进制的数值，即为字符串的哈希值。
例如 $X_nX_n-1...X_2X_1X_0$ ，映射公式为  
 $X_n * p^n + ... + X_2 * p^2 + X_1 * p + X_0$ 
> 1. 任何字符不得映射成0，如 A -> 0,则AA -> 0
> 2. 通常认为，P 取131和13331，Q 取 $2^{64}$ （可用C++中的unsigned long long类型，超出部分自动取模）

字符串前缀和公式  
$$
h[i] = h[i - 1] * P + str[i]
$$  
区间和公式  
$$
h[l, r] = h[r] - h[l - 1] * P^{r - l + 1}
$$  
> 区间和公式的理解: 
> ABCDE 与 ABC 的前三个字符值是一样，只差两位，
乘上 $P^2$ 把 ABC 变为 ABC00，再用 ABCDE - ABC00 得到 DE 的哈希值。
```C++
// 初始化
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 区间和
// p[i]表示p的i次方
unsigned long long query(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
```

# 常用STL
### vector
变长数组
```C++
// 初始化
vector<int> a;
vector<int> a(10);                // 长度为10的vector
vector<int> a(10, -3);            // 长度为10，初始化为-3
vector<int> a[10];                // 每个数组元素都是一个vector

// 操作
a.size()                         // 返回vector的元素个数，O(1)
a.empty()                       // 返回是否为空,O(1)
a.clear()                       // 清空vector
a.front()/a.back()
a.push_back() / a.pop_back()
a.begin() / a.end()
a < b                           // 从前往后比较a和b的值
// 遍历
for (int i = 0; i < a.size(); i ++ )
    cout << a[i] << " ";

for (vector<int>::iterator i = a.begin(); i != a.end(); i ++)
    cout << *i << " ";

for (auto x : a)
    cout << x << " " ;

```
倍增思想：
系统为某一程序分配空间时，所需时间与空间大小无关，与申请次数有关
因此变长数组先分配一定空间，再次申请2倍的空间。申请空间的次数是logn，每次申请复制元素的时间为O(1)

### pair
自带比较，只比较第一个
```C++
pair<int, int> a;
p = make_pair(10, "hlo");
p = {20, "abc"};
a.first()
a.second()
```

### string
字符串
substr() -- 返回子字符串
c_str() -- 返回string对应字符数组的头指针
```C++
string a = "hello";
a += "world";
a += 'c';
a.substr(1, 2);                         // 从下标1开始，输出2个
printf("%s\n", a.c_str());              // 让printf也能输出string
```
### queue
队列
push() -- 插入队尾
front() -- 读出队头
pop() -- 取下队头
```C++
queue<int> q;
q.push();
q.front();
q.back();
q.pop();
```

### priority_queue
优先队列，实际是一个堆，默认大根堆，想要小根堆可以直接插入负数，也可 $priority_queue<int, vector<int>,greater<int>> heap$  
push() -- 插入队尾
top() -- 读出队头
pop() -- 取下队头
### stack
栈
push() -- 入栈
top() -- 读出栈顶
pop() -- 弹出栈顶

### deque
双端队列，队头队尾都可以插入和删除,并且支持随机访问
```C++
size()
empty()
clear()
front()
back()
push_back()
pop_back()
begin()
end()
```

### set, multiset
基于平衡二叉树（红黑树），动态维护有序序列
set不能有重复元素， multiset可以
```C++
insert() -- 插入
find() -- 查找
count() -- 返回某个数的个数
erase() -- 输入一个数时删除所有x，O(k+logn)；输入迭代器时删除这个迭代器
lower_bound(x) -- 返回大于等于x的最小的迭代器
upper_bound(x) -- 返回大于x的最小的迭代器
```
### map, multimap
基于红黑树
```C++
insert() -- 插入的参数是一个pair
erase() -- 输入pair或者迭代器
find()
// 可以像数组一样用
map[first] = second;        // O(logn)
lower_bound()
upper_bound()
```
### unordered_set, unordered_map, unordered_multiset, unordered_multimap
哈希表
与上面类似，增删查改的时间复杂度是O(1), 缺点是不支持lower_bound()/upper_bound(), 不支持迭代器的++、--
### bitset
压位
```C++
bitset<10000> s;
~, &, |, ^
>>, <<
==, !=
[]
count() -- 返回有多少个1
any() -- 返回是否至少有一个1
none() -- 返回是否全为0
set() -- 把所有位置变成1
set(k, v) -- 把第k位变成1
reset() -- 把所有位变成0
flip() -- 全部取反
flip(k) -- 把第k位取反
```