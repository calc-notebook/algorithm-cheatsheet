/*
Tongji Open Judge, Onsite 2017, Problem B. 打发时间
Retrieved from http://acm.tongji.edu.cn/problem.php?cid=1003&pid=1
Finished, By Gao Shuqi, on 2018-03-27.
*/

#include <iostream>
#define bnd 10000000000000
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		long long ans=1;
		int M, N;
		scanf("%d%d", &M, &N);
		for (int i = 1; i <= N; i++) {
			ans *= M;
			ans %= bnd;
		}
		int cnt=0;
		long long tmp = ans;
		while (tmp > 0) { tmp /= 10; cnt++; }
		if (cnt < 13) {
			printf("Case #%d\n", ii);
			for (int i = 1; i <= 13 - cnt; i++) printf("0");
			printf("%lld\n", ans);
		}
		else
			printf("Case #%d\n%lld\n",ii,  ans);
	}
	return 0;
}
