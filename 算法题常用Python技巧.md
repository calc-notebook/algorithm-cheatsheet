# Suan

## 1. 获得排序后下标

```python
# python排序并保留索引值
a = [3,4,1,7,2]
from operator import itemgetter
nums = sorted(enumerate(nums), key=lambda x: x[1]) # [(2, 1), (4, 2), (0, 3), (1, 4), (3, 7)]
```



```pythn
[index for index, value in sorted(enumerate(a), key=itemgetter(1))] # [2, 4, 0, 1, 3]
```

## 2. 快速排序

```python
quick_sort = lambda array: array if len(array) <= 1 else quick_sort([item for item in array[1:] if item <= array[0]]) + [array[0]] + quick_sort([item for item in array[1:] if item > array[0]])
```

方案二：

```python
def quick_sort(array, left, right):
    if left >= right:
        return
    low = left
    high = right
    key = array[low]
    while left < right:
        while left < right and array[right] > key:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= key:
            left += 1
        array[right] = array[left]
    array[right] = key
    quick_sort(array, low, left - 1)
    quick_sort(array, left + 1, high)
```

## 3. 深度优先搜索

```python
def iter_dfs(G,s):
    S,Q=set(),[]
    Q.append(s)
    while Q:
        u = Q.pop()
        if u in S:continue
        S.add(u)
        Q.extend(G[u])
        yield u
```

## 4. 广度优先搜索

```python
# 广度优先搜素，并逆转图
def bfs(G,s):
    P, Q = {s:None}, []
    while Q:
        u = Q.pop(0) # pop the head element
        for v in G[u]:
            if v in P: continue
            P[v] = u
            Q.append(v)
    return P
```

## 5. 拓扑排序

```python
def dfs_topsort(G):
    S,res=set(),[]
    def recurse(u):
        if u in S: return
        S.add(u)
        for v in G[u]:
            recurse(v)
        res.append(u)
    for u in G:
        recurse(u)
    res.reverse()
    return res
```

## 6. 堆排序

```python
import heapq
a = [1,3,2]
heapq.heapify(a)
heapq.heappush(a, 0)
print(heappop(a))
print(heappop(a))
print(heappop(a))
```

## 7. 二维空数组

```python
dp = [[False] * n for _ in range(n)]
```

