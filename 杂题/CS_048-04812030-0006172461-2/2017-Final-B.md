### 2017-Final-B: 抓住那头牛

**总时间限制**: 2000ms **内存限制**: 65536kB

**描述**

农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点$N(0<=N<=100000)$，牛位于点$K(0<=K<=100000)$。农夫有两种移动方式：

1. 从$X$移动到$X-1$或$X+1$，每次移动花费一分钟
2.  从$X$移动到$2X$，每次移动花费一分钟 假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？ 

**输入**

两个整数，$N$和$K$

**输出**

一个整数，农夫抓到牛所要花费的最小分钟数

**样例输入**

```
5 17
```



**样例输出**

```
4
```

**题解**

本题有两种思路，一是采用动态规划的思想，而是采用BFS。分别对两种算法进行了实现，其中BFS的时间复杂度更低。

```c++
/* Dynamic Processing */
int catchCows_dp(int person, int cow){
	memset(visited, 0, sizeof(visited));
	memset(cost, -1, sizeof(cost));

	cost[person] = 0;
	visited[person] = true;

	bool finished = false;
	while (!finished)
	{
		finished = true;
		for (int idx = 0; idx<N_MAX; idx++){
			if (!visited[idx]) { finished = false; continue; }
			if (idx != 0) { if (cost[idx - 1] == -1 || cost[idx - 1]>cost[idx] + 1) cost[idx - 1] = cost[idx] + 1; visited[idx - 1] = true; }
			if (idx != N_MAX) { if (cost[idx + 1] == -1 || cost[idx + 1]>cost[idx] + 1) cost[idx + 1] = cost[idx] + 1; visited[idx + 1] = true; }
			if (idx * 2 <= N_MAX) { if (cost[idx * 2] == -1 || cost[idx * 2]>cost[idx] + 1) cost[idx * 2] = cost[idx] + 1; visited[idx * 2] = true; }
		}
	}

	return cost[cow];
}
```



```c++
/* Breadth-First e */
int catchCows_bfs(int person, int cow){
	memset(visited, 0, sizeof(visited));
	memset(cost, -1, sizeof(cost));

	queue<int> waitzone;
	while (!waitzone.empty()) waitzone.pop();

	waitzone.push(person);
	visited[person] = true;
	cost[person] = 0;
	while (!waitzone.empty() && !visited[cow]){
		int curPos = waitzone.front();
		waitzone.pop();
		
		if (curPos < N_MAX-1 && !visited[curPos + 1]) {
			visited[curPos + 1] = true;
			cost[curPos + 1] = cost[curPos] + 1;
			waitzone.push(curPos + 1);
		}
		if (curPos > 0 && !visited[curPos - 1]) {
			visited[curPos - 1] = true;
			cost[curPos - 1] = cost[curPos] + 1;
			waitzone.push(curPos - 1);
		}
		if (curPos * 2 < N_MAX && !visited[curPos * 2]) {
			visited[curPos * 2] = true;
			cost[curPos * 2] = cost[curPos] + 1;
			waitzone.push(curPos * 2);
		}
	}
	return cost[cow];
}
```

