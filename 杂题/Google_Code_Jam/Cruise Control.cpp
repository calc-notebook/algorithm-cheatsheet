/*
Google Code Jam, Practice Section 2018, Problem C. Cruise Control
Retrieved from https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000524
Finished, By Gao Shuqi, on 2018-03-31.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, D;
struct Horse{
	int pos;
	int spd;
}horse[1008];

bool cmp(Horse a, Horse b) { return (a.pos > b.pos) ? true : false; }

int main() {
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