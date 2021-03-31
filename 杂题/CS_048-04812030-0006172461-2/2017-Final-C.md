### 2017-Final-C: 怪盗基德的滑翔翼

**总时间限制**: 1000ms **内存限制**: 65536kB

**描述**

怪盗基德是一个充满传奇色彩的怪盗，专门以珠宝为目标的超级盗窃犯。而他最为突出的地方，就是他每次都能逃脱中村警部的重重围堵，而这也很大程度上是多亏了他随身携带的便于操作的滑翔翼。有一天，怪盗基德像往常一样偷走了一颗珍贵的钻石，不料却被柯南小朋友识破了伪装，而他的滑翔翼的动力装置也被柯南踢出的足球破坏了。不得已，怪盗基德只能操作受损的滑翔翼逃脱。



![img](http://media.openjudge.cn/images/upload/1340073200.jpg) 



假设城市中一共有N幢建筑排成一条线，每幢建筑的高度各不相同。初始时，怪盗基德可以在任何一幢建筑的顶端。他可以选择一个方向逃跑，但是不能中途改变方向（因为中森警部会在后面追击）。因为滑翔翼动力装置受损，他只能往下滑行（即：只能从较高的建筑滑翔到较低的建筑）。他希望尽可能多地经过不同建筑的顶部，这样可以减缓下降时的冲击力，减少受伤的可能性。请问，他最多可以经过多少幢不同建筑的顶部（包含初始时的建筑）？ 

**输入**

输入数据第一行是一个整数$K（K < 100）$，代表有K组测试数据。 每组测试数据包含两行：第一行是一个整数$N(N < 100)$，代表有N幢建筑。第二行包含N个不同的整数，每一个对应一幢建筑的高度$h（0 < h < 10000）$，按照建筑的排列顺序给出。

**输出**

对于每一组测试数据，输出一行，包含一个整数，代表怪盗基德最多可以经过的建筑数量。

**样例输入**

```
3 
8
300 207 155 299 298 170 158 65 
8 
65 158 170 298 299 155 207 300 
10
2 1 3 4 5 6 7 8 9 10
```

**样例输出**

```
6 
6 
9
```

**解答**

此题可以通过动态规划在线性时间内求解。

算法中保留了两个版本，一个版本的思路是认为怪盗基德进过的建筑必须是连续的，代码如下：

```c++
/* dp-version */
int calulate_dp1(int *data, int length){
	int dp_left[N_MAX], dp_right[N_MAX];
	dp_left[0] = 1;
	dp_right[length - 1] = 1;
	for (int idx = 1; idx < length; idx++){
		if (data[idx]>data[idx - 1]) dp_left[idx] = dp_left[idx - 1] + 1;
		else dp_left[idx] = 1;
		if (data[length - 1 - idx] > data[length - idx]) dp_right[length - 1 - idx] = dp_right[length - idx] + 1;
		else dp_right[length - idx - 1] = 1;
	}
	int answer = 0;
	for (int idx = 0; idx < length; idx++) answer = max(max(answer, dp_left[idx]), dp_right[idx]);
	return answer;
}
```

另一个版本认为怪盗基德经过的建筑不必要是连续的：

```c++
int calculate_dp2(int *data, int length){
	int dp_left[N_MAX], dp_right[N_MAX];
	dp_left[0] = 1;
	dp_right[length - 1] = 1;
	for (int idx = 1; idx < length; idx++){
		dp_left[idx] = 1;
		for (int p = 0; p < idx; p++){
			if (data[idx]>data[p]) dp_left[idx] = max(dp_left[idx], dp_left[p] + 1);
		}
	}
	for (int idx = length-2; idx >=0; idx--){
		dp_right[idx] = 1;
		for (int p = length-1; p > idx; p--){
			if (data[idx]>data[p]) dp_right[idx] = max(dp_right[idx], dp_right[p] + 1);
		}
	}
	int answer = 1;
	for (int idx = 0; idx < length; idx++) answer = max(max(answer, dp_left[idx]), dp_right[idx]);
	return answer;
}
```

原题的考虑是基于第二种思想设计的。

**总结**

本题中需要正方两次求最大递减子序列，在复制从左往右遍历的代码到到从右往左遍历的部分时，漏修改了变量，导致多次**WA**.