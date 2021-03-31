### 2017-Final-D: Checking an Alibi

**总时间限制**: 1000ms **内存限制**: 65536kB

**描述**

A crime has been committed: a load of grain has been taken from the barn by one of FJ's cows. FJ is trying to determine which of his $C (1 <= C <= 100) $cows is the culprit. Fortunately, a passing satellite took an image of his farm $M (1 <= M <= 70000)$ seconds before the crime took place, giving the location of all of the cows. He wants to know which cows had time to get to the barn to steal the grain.  Farmer John's farm comprises $F (1 <= F <= 500) $fields numbered 1..F and connected by $P (1 <= P <= 1,000)$ bidirectional paths whose traversal time is in the range $1..70000$ seconds (cows walk very slowly). Field 1 contains the barn. It takes no time to travel within a field (switch paths).  Given the layout of Farmer John's farm and the location of each cow when the satellite flew over, determine set of cows who could be guilty.  

NOTE: Do not declare a variable named exactly 'time'. This will reference the system call and never give you the results you really want.

**输入**

* Line 1: Four space-separated integers: F, P, C, and M  
* Lines 2..P+1: Three space-separated integers describing a path: F1,F2, and T. The path connects F1 and F2 and requires T seconds to traverse.  
* Lines P+2..P+C+1: One integer per line, the location of a cow. The first line gives the field number of cow 1, the second of cow 2, etc.

**输出**

* Line 1: A single integer N, the number of cows that could be guilty of the crime.  
* Lines 2..N+1: A single cow number on each line that is one of the cows that could be guilty of the crime. The list must be in ascending order.

**样例输入**

```
7 6 5 8 
1 4 2 
1 2 1 
2 3 6 
3 5 5 
5 4 6 
1 7 9 
1 
4 
5 
3 
7
```

**样例输出**

```
4 
1 
2 
3 
4
```

**来源**

USACO 2005 March Silver

**题解**

本题是标准的通过`Dijkstra`算法求单元最短路径。