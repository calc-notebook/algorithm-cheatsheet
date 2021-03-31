/*
Google Code Jam, Round 1B 2017. Problem B. Stable Neigh-bors
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard#s=p1
回溯法, 时间复杂度O(6^n)，只能完成小规模数据的求解
Completed, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
#define N_MAX 1000
using namespace std;

int N, cnt[6],poc;
int ans[N_MAX];
char map[] = { 'R', 'O', 'Y', 'G', 'B', 'V' };
bool conflict[6][6] = { { true, true, false, false, false, true }, { true, true, true, true, false, true }, { false, true, true, true, false, false }, { false, true, true, true, true, true }, { false, false, false, true, true, true }, { true, true, false, true, true, true } };

bool place(int d) {
	for (int i = 0; i < 6; i++) {
		if (cnt[i] <= 0) continue;
		if (d != 1 && conflict[ans[d - 2]][i]) continue;
		if (d==N && conflict[ans[0]][i]) continue;
		cnt[i]--;
		ans[d - 1] = i;
		if (d == N) return true;
		bool flag = place(d + 1);
		if (flag) return true;
		ans[d - 1] = -1;
		cnt[i]++;
	}
	return false;
}

int main() {
	freopen("B-small-practice.in", "r", stdin);
	freopen("B-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d%d%d%d%d%d", &N, &cnt[0], &cnt[1], &cnt[2], &cnt[3], &cnt[4], &cnt[5]);
		bool flag = place(1);
		if (!flag) printf("Case #%d: IMPOSSIBLE\n", ii);
		else {
			printf("Case #%d: ", ii);
			for (int i = 0; i < N; i++) printf("%c",map[ans[i]]);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}