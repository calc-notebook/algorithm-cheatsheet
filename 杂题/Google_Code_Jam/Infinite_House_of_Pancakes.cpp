/*
Google Code Jam, Qualification Round 2015, Problem B. Infinite House of Pancakes
Retrieved from https://code.google.com/codejam/contest/6224486/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-03-24.
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int D;
int P[10000];

bool cmp(int a, int b) { return (a > b) ? true : false; }

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &D);
		memset(P, 0, sizeof(P));
		for (int i = 1; i <= D; i++) scanf("%d", &P[i]);
		int cnt, bnd=0,ans=0x7fffffff;
		for (int i = 1; i <= D; i++) if (P[i] > bnd) bnd = P[i];
		for (int j = 1; j <= bnd; j++) {
			cnt = 0;
			for (int i = 1; i <= D; i++) {
				int tmp = P[i];
				while (tmp > j) {
					tmp -= j;
					cnt++;
				}
			}
			cnt += j;
			ans = (ans > cnt) ? cnt : ans;
		}

		printf("Case #%d: %d\n", ii, ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
