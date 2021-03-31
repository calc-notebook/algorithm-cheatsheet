/*
Google Code Jam, Qualification Round 2016, Problem D. Fractiles
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard#s=p3
By Gao Shuqi, on 2018-03-24.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

	freopen("D-small-practice.in", "r", stdin);
	freopen("D-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		if (C == 1) {
			if (S >= K) {
				printf("Case #%d:", ii);
				for (int i = 1; i <= K; i++) printf(" %d", i);
				printf("\n");
				continue;
			}
			else {
				printf("Case #%d: IMPOSSIBLE\n", ii);
				continue;
			}
		}
		else {
			if (S*C<K) {
				printf("Case #%d: IMPOSSIBLE\n", ii);
				continue;
			}
			printf("Case #%d:", ii);
			long long bnd = pow(K, C);
			for (int i = 1; i <= K; i+=C) {
				long long pos = i;
				for (int j = i+1; j <i+ C; j++) pos = (pos - 1)*K + j;
				if (pos>bnd) pos = bnd;
				printf(" %lld", pos);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}