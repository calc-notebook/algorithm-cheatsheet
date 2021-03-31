/*
Google Code Jam, Round 1B 2017, Problem A. Steed 2: Cruise Control
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard
归纳, 模拟
Completed, By Gao Shuqi, on 2018-04-15.
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, D;
struct Horse{
	int pos;
	int spd;
}horse[1008];

bool cmp(Horse a, Horse b) { return (a.pos > b.pos) ? true : false; }

int main() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &D, &N);
		for (int i = 1; i <= N; i++) scanf("%d%d", &horse[i].pos, &horse[i].spd);
		sort(horse + 1, horse + 1 + N, cmp);
		double maxium = 0;
		for (int i = 1; i <= N; i++) {
			if (horse[i].pos >= D) continue;
			double tmp = (double)(D - horse[i].pos) / horse[i].spd;
			if (tmp > maxium) maxium = tmp;
		}
		double ans = D / maxium;
		printf("Case #%d: %.6f\n", ii, ans);
	}
	return 0;
}