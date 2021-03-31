/*
Tongji Open Judge, 网络赛 2017, Problem D. 卡牌游戏
Retrieved from http://acm.tongji.edu.cn/problem.php?cid=1001&pid=3
Finished, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int N, tmp, cnt;
int data[2001];
int Min(int a, int b) { return (a < b) ? a : b; }

int construct(int d) {
	if (data[d + 1000]>0) return 1;
	int a=0x7fffffff;
	for (int i = 0; i <= 2000; i++) {
		if (data[i] == 0) continue;
		for (int j = 1; j <= data[i]; j++) {
			data[i] -= j;
			int b = construct(d - j*(i - 1000));
			data[i] += j;
			if (b == 0) continue;
			a = Min(a, b+j);
		}
	}
	if (a == 0x7fffffff) return 0;
	else return a;
}

int main() {

	memset(data, 0, sizeof(data));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		data[tmp + 1000]++;
	}
	if (data[1000] > 0) cnt = 1;
	else {
		cnt = construct(0);
	}
	if (cnt == 0) cnt = -1;
	printf("%d\n", cnt);
	getchar();
	getchar();
	return 0;
}