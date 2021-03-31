# Algorithm-Repo

## Tutorial
[Algorithm](https://github.com/Tenant/Algorithm-Repo/blob/master/Algorithm-Tutorial.md)

[Data Structure](https://github.com/Tenant/Algorithm-Repo/blob/master/Data-Structure-Tutorial.md)

[Coding]()

## CS_048-04812030-0006172461-2

### 2017-Final-A 反反复复
**Source**: http://algorithm.openjudge.cn/final2017/A/

**Type**: 字符串操作

**Code**: https://github.com/Tenant/Algorithm-Repo/blob/master/CS_048-04812030-0006172461-2/2017-Final-A.cpp


### 2017-Final-B 抓住那头牛
**Source**:

**Type**:

**Code**:

动态规划
```c++
void catchCows_dp(int person, int cow){
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

	printf("%d\n", cost[cow]);
}
```


### 2018-3-A 平面最近點對
**Source**: http://algorithm.openjudge.cn/2018test3/A/

**Type**: 歸并

**Code**: https://github.com/Tenant/Algorithm-Repo/blob/master/CS_048-04812030-0006172461-2/2018-3-A.cpp

輸入數據中點的坐標均爲整型，但計算點對距離時需要顯示的將坐標轉換為double型：

```c++
double getDistance(Point2d a, Point2d b){
	return sqrt(((double)a.x - (double)b.x)*((double)a.x - (double)b.x)
		      + ((double)a.y - (double)b.y)*((double)a.y - (double)b.y));
}
```

原地歸并排序的庫函數:

```c++
inplace_merge(data, data + length / 2, data + length, compare_Y);
```

程序中預先申明的數組空間小於測試數據大小時，會產生`Exceed Time Limit`的錯誤

定義函數用於`sort`時，不能是小於等於或大於等於：

```c++
bool compare_X(Point2d a, Point2d b){
	return a.x < b.x;
}
```

可以通過這樣的方式設置`Infinity`：
```c++
if (length == 1) return 1e11;
```

### 2018-3-E 股票交易
**Source**: 

**Type**: 动态规划，股票交易问题


### 2018-3-F 棋盘分割问题
**Source**: http://algorithm.openjudge.cn/2018test3/F/

**Type**: 动态规划，递归，棋盘分割问题

**Code**: https://github.com/Tenant/Algorithm-Repo/blob/master/CS_048-04812030-0006172461-2/2018-3-F.cpp


## Google_Code_Jam


## TJOJ


## UVa


## LeetCode
