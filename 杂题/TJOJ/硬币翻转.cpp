/*
Tongji OJ, Problem 1085. 硬币翻转
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1085
归纳法.
Completed, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
using namespace std;

int main() {
	long long N, M, K;
	scanf("%lld%lld%lld", &N, &M, &K);
	long long L = N;
	long long S = M;
	long long cnt;
	long long n = S / K;
	if (K == 1) cnt = S;
	else if (K == S) cnt == 1;
	else if (K < S && ((S-(n-1)*K) % 2 == 0)) cnt = S / K + 1;
	else cnt = -1;
	
	printf("%lld\n", cnt);
	return 0;
}