/*
Google Code Jam, Practice Section 2018, Problem D. Bathroom Stalls
Retrieved from https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000652
Finished, By Gao Shuqi, on 2018-03-31.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Stall{
	long long start;
	long long length;
	bool operator<(const Stall &b) const {
		if (length > b.length) return false;
		else if (length == b.length && start < b.start) return false;
		else return true;
	}
};
long long N, K;
priority_queue<Stall> q;

int  main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%lld%lld", &N, &K);
		while (!q.empty()) q.pop();
		Stall tmp;
		tmp.length = N;
		tmp.start = 1;
		q.push(tmp);
		for (long long i = 1; i <= K; i++) {
			tmp = q.top();
			q.pop();
			long long mid = tmp.start + (tmp.length - 1) / 2;
			if (mid != tmp.start) { Stall tmp1; tmp1.start = tmp.start; tmp1.length = mid - tmp.start; q.push(tmp1); }
			if (tmp.length != 1) { Stall tmp1; tmp1.start = mid+1; tmp1.length =tmp.length-mid-1+tmp.start; q.push(tmp1); }
		}
		printf("Case #%d: %lld %lld\n", ii, tmp.length / 2, (tmp.length - 1) / 2);
	}
}