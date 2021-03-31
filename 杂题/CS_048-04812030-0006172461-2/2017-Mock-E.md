## 2017-Mock-E: 重要逆序对

**总时间限制**: 1000ms **内存限制**: 256000kB



**描述**

给定N个数的序列a1,a2,...aN，定义一个数对(ai, aj)为“重要逆序对”的充要条件为 i < j 且 ai > 2aj。求给定序列中“重要逆序对”的个数。 



**输入**

本题有多个测试点，每个测试点分为两行：第一行为序列中数字的个数$N（1 ≤ N ≤ 200000）$，第二行为序列$a1, a2 ... aN(0 ≤a ≤ 10000000)$，由空格分开。$N=0$表示输入结束。



**输出**

每个测试点一行，输出一个整数，为给序列中“重要逆序对”的个数。



**样例输入**

```c++
10 
0 9 8 7 6 5 4 3 2 1 
0
```



**样例输出**

```c++
16
```



**提示**

请注意答案范围，如果使用`printf`输出`long long`类型，请用`%lld`



**来源**

[Open Judge](http://algorithm.openjudge.cn/2017mock/E/)



**题解**

本题是采用分治法求最大逆序对的变式。



```c++
long long calInversions(int* data, int length){
	if (length == 1) return 0;
	long long cnt_left = calInversions(data, length / 2);
	long long cnt_right = calInversions(data + length / 2, length - length / 2);
	long long cnt_mixture = 0;
	int idx1 = 0, idx2 = length / 2;
	while (idx1 < length / 2 && idx2 < length){
		if (data[idx1] <= 2 * data[idx2]) {
			idx1++;
		}
		else{
			cnt_mixture += (length / 2 - idx1);
			idx2++;
		}
	}
	inplace_merge(data, data + length / 2, data + length);
	return cnt_left + cnt_right + cnt_mixture;
}
```



