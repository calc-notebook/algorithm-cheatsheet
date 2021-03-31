# Data Structure

## 1. Union-Find

> 凡是经由==并查集==可以解决的问题，通过==DFS==或==BFS==总是可解的。但在图中结点==动态增加==的情境下，并查集操作往往有更高的效率；但并查集不能用于结点==减小==的情景。

```c++
int root[N_MAX];

int findRoot(int idx){
    if(root[idx]==-1) return idx;
    int ancestor = findRoot(root[idx]);
    root[idx] = ancestor;
    return ancestor;
}
```

## 2. Queue

```c++
#include <queue>
using namespace std;

queue<T> Q;
Q.push(x);
Q.front();
Q.pop();
Q.empty();
```



## 3. Priority Queue

```c++
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> left; // Big-end Heap
priority_queue<int, vector<int>, greater<int>> right; // Small-end Heap
left.push();
left.pop();
left.top();
left.empty();
```

