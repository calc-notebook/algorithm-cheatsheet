/*
Google Code Jam, Qualification Round 2014, Problem A. Magic Trick
Retrieved from https://code.google.com/codejam/contest/2974486/dashboard
Finished, By Gao Shuqi, on 2018-03-24.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	freopen("A-small-practice.in", "r", stdin);
	freopen("A-small-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		int m, n;
		int before[5][5], after[5][5];
		scanf("%d", &m);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++)
				scanf("%d", &before[i][j]);
		}
		scanf("%d", &n);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++)
				scanf("%d", &after[i][j]);
		}
		int cnt = 0, pos;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (before[m][i] != after[n][j]) continue;
				cnt++;
				pos = before[m][i];
			}
		}
		if (cnt == 0)
			printf("Case #%d: Volunteer cheated!\n", ii);
		else if (cnt==1)
			printf("Case #%d: %d\n", ii, pos);
		else
			printf("Case #%d: Bad magician!\n", ii);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}