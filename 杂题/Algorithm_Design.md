# Algorithm Design

## 1. Stable Matching



## 2. Algorithm Analysis



## 3. Graphs

### 3.1 Basic Definitions and Applications

**Graph representation**: adjacency matrix

**Code**:

创建单链表：

```c++
#include <vector>
using namespace std;

class Edge{
public:
    int nextNode;
    int cost;
}
vector<Edge> edge[N];
```

清空单链表：

```c++
for(int idx=0;idx<N;idx++) edge[idx].clear();
```

追加边：

```c++
Edge newedge;
int startNode;
scanf("%d%d%d",&startNode,&newedge.nextNode,&newedge.cost);
edge[startNode].push_back(newedge);
```

遍历某个结点的所有邻接信息：

```c++
for(int idx=0;idx<edge[p].size();idx++){
    // do something
}
```

删除结点中的某条边时：

```c++
edge[p].erase(edge[p].begin()+i,edge[p].begin()+i+1);
```

### 3.2 Graph Connectivity and Graph Traversal

### 3.2.1 BFS

```c++
#include <queue>

queue<T> waitingzone;
waitingzone.push(startPoint);
while(waitingzone.empty()==false){
    T p = waitingzone.front();
    waitingzone.pop();
    // traversal all edges from p
    // append all points connected with p to waitingzone
}
```

#### 3.2.2 DFS

```c++
void DFS(int pos, int dst){
    // do something
}
```

#### 3.3.3 Flood Fill

```c++
int label=0;
for(int idx=0;idx<N;idx++){
    if(visited[idx]) continue;
    int startpoint=idx;
    // do DFS or BFS from startpoint
    // and level all recently visitedly
    // points as label
    label++;
}
```

### 3.3 Testing Bipartiteness

Traverse and dyne and check compatibility.

### 3.4 Connectivity in Directed Graphs

Still BFS or DFS, with the constraints that the edge is directed.

### 3.5 DAGs and Topological Ordering

通过==邻接表==保存图，维护一个数组记录所有顶点的==入度==，将==入度为零==的结点加入==结果队列==，并将所有==相邻顶点==的入度减一。

## 4. Greedy Algorithm

`贪心算法编程实现通常不复杂，关键在于找到正确的贪心策略。`

### 4.1 Coin changing

**Pseudo-code**:

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-19_085651.png)

### 4.2 Interval scheduling

**Goal**: Find the maximum subset of mutually compatible jobs.

**Pseudo-code**:

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-19_085945.png)

**Computational tractability**: $O(n \log n)$.

### 4.3 Interval Partitioning

**Goal**: Find the minimum number of classrooms to schedule all lectures so that no two lectures occur at the same time in the same room.

**Pseudo-code**:

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-19_085945.png)

**Computational tractability**: $O(n \log n)$.

### 4.4 Scheduling to minimize lateness

**Goal**: schedule all jobs to minimize ==maximum== lateness.

**Pseudo-code(==earliest deadline first==)**: 

![Alt image](http://images-repo.oss-cn-beijing.aliyuncs.com/1.png)

> Observation 1: There exists an optimal schedule with on idle time.
>
> Observation 2: The earliest-deadline-first schedule has no idle time.

> Observation 3: The earliest-deadline-first schedule has no inversion.
>
> Observation 4: If a schedule (with on idle time) has an inversion, it has one with a pair of inverted jobs scheduled consecutively.
>
> $\ell'_j =f'_j-d_j=f_i-d_i<= f_i-d_i<=\ell_i$

**Proof**:

**(Exchange Argument)** Define $S^*$ to be an optimal schedule that has the fewest number of inversions

**Computational tractability**: $O(n \log n)$.

### 4.5 Optimal caching

**Goal**: Eviction schedule that minimizes number of evictions.

**Farthest-in-future(Clairvoyant Algorithm)**. FF is optimal eviction schedule.

**Farthest-in-future** is optimal, but limited offline; its Online alternative is **LRU**. However, with a circularly visited array, **LRU** is the ==worst==.

### 4.6 Dijkstra’s algorithm

**Goal**: Find the shortest directed path from $s$ to $t$.

**Pseudo-code**:

![Alt image](http://images-repo.oss-cn-beijing.aliyuncs.com/2.png)

**Code**:

```c++
#include <queue>

 priority_queue<int, vector<int>, greater<int>> minHeap;

if(!minHeap.empty()) minHeap.pop();

memset(d,-1,N);
d[0]=0;
for(int idx=0;idx<N;idx++) minHeap.push(d[idx]);
while(!minHeap.empty()){
    in
}

```

**Proposition**. 若图中存在负边，不能将图中所以边加上同一正数后应用$Dijkstra$算法。

**Extensions**

> Shortest paths in undirected graphs: $d(v)<=d(u)+\ell(u,v)$
>
> Maximum capacity paths: $d(v)>=min\{\pi(u),c(u,v)\}$
>
> Maximum reliability paths: $dv>=d(u)\times\gamma(u,v)$

### 4.7 Minimum spanning trees

**Proposition 1**. Let $T=(V,F)$ be a subgraph of $G=(V,E)$. TFAE:

- $T$ is a spanning tree of $G$.

**Proposition 2**. Given a connected graph $G$, with edges costs that are all distinct, $G$ has a unique minimum spanning tree.

**Proposition 3**. Let $G$ be an arbitrary connected, undirected graph with a distinct cost on every edge. Suppose $e^*$ is the cheapest edge in $G$, then there is a minimum spanning tree $T$ if $G$ that contains the edge $e^*$.

**Proposition 4** . 若图中权值最小的边唯一，则该边必存在于该图的全部最小生成树中。

**Proposition 5** . 若图中权值最大的边唯一，则该边仍有可能存在于该图的最小生成树中。

**Proposition 6** . 最小生成树是最大连通图。

**Proposition 7**. 若$T$为$G$的最小生成树，$G’$为$G$中全部边权值平方后的新图，则$T$仍为$G'$的最小生成树。

**Proposition 8**. 最小生成树算法适用于边权值为负的情况。

**Proposition 9**. 假设边$e^*$是联通图$G$ 的两个割集的==唯一权重最小==的边，则该边==必存在==于该图的全部最小生成树中。

**Proposition 10**. 假设边$e^*$==不是==连接图$G$的两个割集的边中==权值最小==的，则该边==仍可能==存在于该图的最小生成树中。

**Proposition 11**. 假设边$e^*$不是连接图$G$的任意两个割集的边中权值最小的边，则该边==比不存在==于该图的最小生成树中。

**Proposition 12**.   假设$G$中存在环，边$e^*$某一环中权值最大的边，则该边==必不存在==于$G$的最小生成树中；若$e^*$非某一环中权值最大的边，则该边==不一定==不存在于$G$的最小生成树中；若$e^*$非==任一==环中权值最大的边，或该边不存在于任一环上，则该边==必存在==于$G$的最小生成树中。

#### 4.7.1 Prim’s algorithm

![alt image](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-10-22_164954.png)



#### 4.7.2 Kruskal’s algorithm

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-10-22_165244.png)

**Code**

```c++

```



#### 4.7.3 Reverse-delete algorithm

**Fact**. Can be implemented in $O(m\log n(\log \log n)^3)$ time.

### 4.8 Single-link Clustering

**Goal**: Given a set $U$ of $n$ objects labeled $p_1$, $…$, $p_n$, partition into clusters so that objects in different clusters are far apart.

**Algorithm 1** 

```c++
form a graph on the node set, corresponding to n clusters.
find the closest pair of objects such that each objects is in a different cluster, and add an edge between them
Repeat n-k times until there are exactly k cluster
```

**Algorithm 2**

```c++
find an MST and delete the k-1 longest edges
```

### Exercises

2. solved
3. ==Bin packing== is, as well as ==knapsack==, a classic NP problem.

14. ==“点对区间的覆盖”问题==

    ```c++
    class Region{
        public:
        int head, tail;
        bool operator<(Region b) const{
            return this->tail<b.tail;
        }
    }
    
    sort(regions,regions+N);
    int cnt=0;
    int pos=0;
    for(int idx=0;idx<N;idx++){
        if(regions[idx].head >= pos){
            cnt++;
            pos=regions[idx].tail;
        }
    }
    printf("%d\n",&cnt);
    ```

    ==“区间对区间的覆盖”问题==

    ```c++
    class Region{
        public:
        int head, tail;
        bool operator<(Region b) const {reuturn this->tail<b.tail;}
    }
    
    sort(regions, regions+N);
    for(int idx=0;idx<N;idx++){
        if(regions[idx].head >= pos){
            tail=maximum_of_endtime_of_all_elasped_region;
            cnt++;
        }
    ```

    9. ==“最小生成树”==和==“最小瓶颈树”==。最小瓶颈树不一定是最小生成树，但最小生成树一定是最小瓶颈树。


## 5. Divide and Conquer

### 5.1 Merge-sort

**Def**. $T(n)$ is the maximum comparing of merge-sorting, then

$T(n)=2T(n/2)+n$

$T(n)=O(n \log_2n)$

### 5.2 Counting Inversions

**Pseudo-code**

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-05_155734.png)

**Code**

```c++
#include <algorithm>
#include <cstring>

int count_inversions(int* data, int length){
    if(length==1) {return 0;}
    
    int mid = length/2;
    int cnt_left = count_inversions(data,mid);
    int cnt_right = count_inversions(data+mid, length-mid);
    
    int cnt_cross = 0;
    int p=0, q=mid;
    int* newArray b;
    int cnt=0;
    while(p<mid && mid<length){
        if(data[p]>data[q]){
            cnt_cross += (mid - p);
            b[cnt++] = data[p];
            q++;
        }
        else{
            b[cnt++] = data[q];
            p++;
        }
    }
   data = b; 
}
```

### 5.3 Closest Pair of Points

> If points are on a line, the algorithm satisfies $O(n \log n)$.
>
> **Pseudo-code**

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-05_163749.png)

**Code**

```c++
#include <vector>
#include <algorithm>

class Point2d{
public:
    int x, y;
    bool operator<(Point2d b) const{
        return this->x<b.x;
    }
}

double closest_pair(Point2d* data, int length){
    for (int idx = 0; idx < length; idx++) printf("(%d,%d)\t", data[idx].x, data[idx].y);
    printf("\n");
    if (length == 1) return -1;
    if (length == 2) return sqrt((data[0].x - data[1].x)*(data[0].x - data[1].x) + (data[0].y - data[1].y)*(data[0].y - data[1].y));
    double sigma1 = closest_pair(data, length / 2);
    double sigma2 = closest_pair(data + length / 2, length - length / 2);
    double sigma = (sigma1<sigma2) ? sigma1 : sigma2;
    double L = (data[length / 2 - 1].x + data[length / 2].x) / 2.;
    Point2d local_points[N_MAX];
    for (int idx = 0; idx< length; idx++){
        if (abs(data[idx].x - L) > sigma) continue;
        int head = (idx - 5)>0 ? (idx - 5) : 0;
        int tail = (idx + 5)<length ? (idx + 5) : (length - 1);
        sort(data + head, data + tail + 1, compare_Y);
        for (int p = head; p <= tail; p++){
            double temp_dist = sqrt((data[p].x - data[idx].x)*(data[p].x - data[idx].x) + (data[p].y - data[idx].y) * (data[p].y - data[idx].y));
            if (temp_dist < sigma) sigma = temp_dist;
        }

    }
    return sigma;

}
```

**Efficiency**

The divide-and -conquer algorithm for finding the closest pair of points in the plane can be implemented in $O(n \log^2n)$ time.

### 5.4 Randomized Quicksort

**Pseudo-code**

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-05_165614.png)

==划分成3部分很重要，可以避免pivot元素同原数组中多个元素相同时出现的退化==

### 5.5 Median and Selection

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-12_151829.png)

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-12_152121.png)



**Solved Exercises**

Solved Exercise1.

## 6. Dynamic Programming

### 6.1 Weighted Interval Scheduling

**Pseudo-code**:

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-18_083914.png)

**Code**:

```c++

```

### 6.3 Segmented Least Squares

**Pseudo-code**:

![](http://images-repo.oss-cn-beijing.aliyuncs.com/2018-11-18_084417.png)

**Code**:

```c++

```

### 6.4 Longest Incremental Sequence

**Formula**:

$dp[1]=1 \\ dp[i]=\max \{1,dp[j]+1|a_j<a_i \text{and } j<i\} $

**Code**:

```c++
int dp[N_MAX];

dp_left[0] = 1;
for (int idx = 1; idx<N; idx++){
    int temp_max = 1;
    for (int p = 0; p<idx; p++){
        if (heights[p]<heights[idx]) temp_max = max(temp_max, dp_left[p] + 1);
    }
    dp_left[idx] = temp_max;
}
```

**Computational tractability**: $O(n \log n)$.

**Exercise**:

[合唱队形](http://git.posslab.space/sukie/Algorithm-Design/blob/master/Algorithm-Analysis/2018-3-B.cpp)

### 6.5 Longest Common Sequence

**Formula**:

假设有两个字符串$S1$和$S2$，其中$S1$长度为$n$，$S2$长度为$m$，用$dp[i][j]$表示$S1$前$i$个字符组成的前缀子串与$S2$前$j$个字符组成的前缀子串的最长公共子串长度，那么：

$dp[0][j]=0, \text{ for all }j\in [0,m] \\dp[i][0]=0 \text{ for all } i \in [0,n] \\ dp[i][j]=dp[i-1][j-1]+1 \text{  if } S1[i]=S2[j] \\ dp[i][j]=\max \{dp[i-1][j], dp[i][j-1] \text{  if } S1[i] \ne S2[j]\}$

**Code**:



**Exercise**:

[最长公共子序列](http://git.posslab.space/sukie/Algorithm-Design/blob/master/Algorithm-Analysis/2018-3-C.cpp)

### 6.6 Sum-largest Sub-Matrix

**Formula**:

子序列和最大：

$dp[0]=data[0]\\ dp[i]=\max\{data[i],dp[i-1]+data[i]\}$

子序列和绝对值最大：

$dp_{max}[0]=data[0] \\ dp_{min}[0]=data[0] \\ dp_{max}[i]=\max \{dp_{max}[i-1] + data[i], dp_{min}[i-1] + data[i] \\ dp_{min}[i]=\min \{dp_{max}[i-1] + data[i], dp_{min}[i-1] + data[i] \}$

子序列乘积最大：

$dp_{max}[0]=data[0] \\ dp_{min}[0]=data[0] \\ dp_{max}[i]=\max \{dp_{max}[i-1] \times data[i], dp_{min}[i-1] \times data[i] \\ dp_{min}[i]=\min \{dp_{max}[i-1] \times data[i], dp_{min}[i-1] \times data[i] \}$

子序列和最大且长度受限：

子矩阵和最大：

$f(0,j,k)=0 \\ f(i,j,k)=\max \{S(i,j,k),S(i,j,k)+f(i-1,j,k)\}$



**Method 1**

**Method 2**



**Exercise**:



### 6.7 Stocking Exchange

**Formula**:



**Exercise**:



## 7. Network Flow


# Algorithm Design

## 1. Graph

### 1.1 MST

#### 2018-2-E

标准最小生成树题目。

一度不能accepted，因为循环条件错误。

```c++
int N;
scanf("%d",&N){
    // do processing
    scanf("%d",&N);
}
```

后修改为如下，成功accepted

```c++
int N;
while(scanf("%d",&N)!=EOF){
    
}
```

题目中有提到有多组测试用例，但未说明有几组以及全部测试用例输入完毕后有什么标识。所以==不能不写==循环，建议读取==EOF==.







## 2. Heap

#### 2018-2-A

构造一个最大堆，一个最小堆，求数列中的中位数。

求解过程中一度超时。原因未使用$cin$读入字符，后修改为如下形式时accepted

```c++
while(N--){
    getchar(); // take care of the '\n\r' from last line input
    char op;
    scanf("%c",&op);
}
```

## 3. Union

#### 2018-2-C

迷宫联通问题，通过并查集创造虚拟节点求解。同样的问题可以采用==图搜索==的方法来解决，但时间复杂度往往不能满足题目的要求。

题目求解时一度出现**顶部虚拟节点**的根节点指向自身的问题，带来segmentation fault的错误。错误时代码为：

```c++
int root_a=getRoot((x_next-1)*N+y_next);
int root_b=getRoot((x-1)*N+y);
if(root_a<root_b){
    root[root_b]=root_a;
}
else{
    root[root_a]=root_b;
}
```

通过讲**line 6**进行如下修改成功accepted.

```c++
int root_a=getRoot((x_next-1)*N+y_next);
int root_b=getRoot((x-1)*N+y);
if(root_a<root_b){
    root[root_b]=root_a;
}
if(root_a>root_b){
    root[root_a]=root_b;
}
```

## A. Loop Termination

### A.1 Loop Finishing

部分题目不给出测试样例的数量，而是通过读文件结束(EOF)来表示测试结束，或者未提及实际有一组样例或多组样例，此时可采用两种形式的循环条件写法。

第一种：

```c++
int N;
while(scanf("%d",&N)!=EOF){
    
}
```

第二种：

```c++
string S1, S2;
while(cin>>S1>>S2){
    
}
```

