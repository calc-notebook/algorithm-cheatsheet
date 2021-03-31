/*
Google Code Jam 2017, Qualification Round, Problem B. Tidy Numbers
Retrieved from https://code.google.com/codejam/contest/3264486/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-03-18.
*/

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

bool cal(long long d) {
	while (d > 0) {
		int q = d % 10;
		d /= 10;
		int p = d % 10;
		if (p > q) return false;
	}
	return true;
}

long long refresh(long long d) {
	int p;
	stack<int> s;
	while (!s.empty()) s.pop();
	p = d % 10;
	d /= 10;
	s.push(p);
	p = d % 10;
	while (d > 0 && p<=s.top()) {
		s.push(p);
		d /= 10;
		p = d % 10;
	}
	d--;
	for (int i = 1; i <= s.size(); i++)
		d = d * 10 + 9;
	return d;
}

int main() {

	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		long long d;
		scanf("%lld", &d);
		for (; d > 0; d=refresh(d)) {
			if (cal(d))
			{
				printf("Case #%d: %lld\n", i, d);
				break;
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}