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