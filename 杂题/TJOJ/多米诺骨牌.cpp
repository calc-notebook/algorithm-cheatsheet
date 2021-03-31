/*
Tongji OJ, Problem 1005. 多米诺骨牌
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1055
动态规划
Completed, By Gao Shuqi, on 2018-04-19.
*/

#include <iostream>
#include <algorithm>
#define N_MAX 200000
using namespace std;

int N, Q;
int poc1, poc2;
long long dp[N_MAX+10];
struct E1{
	int loc;
	int len;
}data1[N_MAX+10];

struct E2{
	int start;
	int end;
}data2[N_MAX+10];

long long cal(int d) {
	if (d == 0) return 0;
	if (dp[d] != -1) return dp[d];
	else {
		long long tmp;
		int length = data1[d].loc - data1[d - 1].loc - data1[d - 1].len;
		tmp = (length > 0) ? (cal(d - 1) + length) : cal(d - 1);
		dp[d] = tmp;
		return tmp;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {scanf("%d%d", &data1[i].loc, &data1[i].len); dp[i] = -1;}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) scanf("%d%d", &data2[i].start, &data2[i].end);
	long long cnt;
	dp[0] = 0;
	for (int i = 0; i < Q; i++) {
		cnt = cal(data2[i].end-1);
		printf("%lld\n", cnt);
	}
	
	getchar();
	getchar();
	return 0;
}