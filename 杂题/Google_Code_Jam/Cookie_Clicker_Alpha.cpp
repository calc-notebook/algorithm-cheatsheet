/*
Google Code Jam, Qualification Round 2014, Problem B. Cookie Clicker Alpha
Retrieved from https://code.google.com/codejam/contest/2974486/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-03-25.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		double C, F, X;
		cin >> C >> F >> X;
		double residue=0, rate=2.0, cnt = 0.0;
		while (residue < C) {
			cnt += (C - residue) / rate;
			residue = C;
			if ((X - C) / rate*F <= C) break;
			residue -= C;
			rate += F;
		}
		cnt += (X - residue) / rate;
		printf("Case #%d: %.7f\n", ii, cnt);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}