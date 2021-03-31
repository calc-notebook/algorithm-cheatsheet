/*
Google Code Jam, Qualification Round 2012, Problem B. Dancing With the Googlers
Retrieved from https://code.google.com/codejam/contest/1460488/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-04-01.
*/

#include <iostream>
using namespace std;

int N, S, P;

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int cnt = 0;
		scanf("%d%d%d", &N, &S, &P);
		for (int i = 1; i <= N; i++) {
			int tmp;
			scanf("%d", &tmp);
			if ((tmp + 2) / 3 >= P) cnt++;
			else if (((tmp + 4) / 3 >= P) && S > 0 && tmp>=2) { S--; cnt++; }
			else {}
		}
		printf("Case #%d: %d\n", ii, cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}