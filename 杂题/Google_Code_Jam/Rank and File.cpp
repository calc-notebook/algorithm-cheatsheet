/*
Google Code Jam, Round 1A 2016. Problem B. Rank and File
Retrieved from https://code.google.com/codejam/contest/4304486/dashboard#s=p1
数论
Completed, By Gao Shuqi, on 2018-04-18.
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#define N_MAX 2500
using namespace std;

int N;
int cnt[N_MAX + 1];
int ans[50],poc;

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i < 2 * N; i++) {
			for (int j = 1; j <= N; j++) {
				int tmp;
				scanf("%d", &tmp);
				cnt[tmp]++;
			}
		}
		poc = 0;
		for (int i = 1; i <= N_MAX; i++) {
			if (cnt[i] % 2 == 1) ans[poc++] = i;
		}
		sort(ans, ans + N);
		printf("Case #%d:", ii);
		for (int i = 0; i < N; i++) printf(" %d", ans[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}