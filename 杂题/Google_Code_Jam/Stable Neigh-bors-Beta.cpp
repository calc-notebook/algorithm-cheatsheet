/*
Google Code Jam, Round 1B 2017. Problem B. Stable Neigh-bors
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard#s=p1
归纳法
Completed, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define N_MAX 1000
using namespace std;

int N, cnt[6], poc;
char ans[N_MAX];
int visited[N_MAX];
char map[] = { 'R', 'O', 'Y', 'G', 'B', 'V' };
bool conflict[6][6] = { { true, true, false, false, false, true }, { true, true, true, true, false, true }, { false, true, true, true, false, false }, { false, true, true, true, true, true }, { false, false, false, true, true, true }, { true, true, false, true, true, true } };

void place(int r, int b, int y, int n) {
	int poc = 0;
	while (r!=0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'R';
		visited[poc] = true;
		poc = (poc + 2) % n;
		r--;
	}
	while (b != 0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'B';
		visited[poc] = true;
		poc = (poc + 2) % n;
		b--;
	}
	while (y != 0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'Y';
		visited[poc] = true;
		poc = (poc + 2) % n;
		y--;
	}
}

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d%d%d%d%d%d", &N, &cnt[0], &cnt[1], &cnt[2], &cnt[3], &cnt[4], &cnt[5]);
		memset(visited, 0, sizeof(visited));
		int num = 0;
		for (int i = 0; i < 6; i++) {
			if (cnt[i]>0) num++;
		}
		if (num == 2) { //只有两种独角兽
			int poc1,poc2;
			for (poc1=0; cnt[poc1] == 0; poc1++);
			for (poc2 = poc1 + 1; cnt[poc2] == 0; poc2++);
			//如果二者不相等或者存在冲突
			if ((cnt[poc1] != cnt[poc2]) || (conflict[poc1][poc2])) { printf("Case #%d: IMPOSSIBLE\n", ii); continue; } //两者不相等
			printf("Case #%d: ", ii);
			for (int i = 0; i < N; i += 2) { printf("%c%c", map[poc1], map[poc2]); }
			printf("\n");
			continue;
		}
		else {
			bool flag = true;
			if (N / 2 < cnt[0] || N/ 2 < cnt[2] || N / 2 < cnt[4]) flag = false;
			else if (cnt[4] <= cnt[1] && cnt[1] != 0) flag = false;
			else if (cnt[0] <= cnt[3] && cnt[3] != 0) flag = false;
			else if (cnt[2] <= cnt[5] && cnt[5] != 0) flag = false;
			if (!flag) { printf("Case #%d: IMPOSSIBLE\n", ii); continue; }
			cnt[0] = cnt[0] - cnt[3];
			cnt[4] = cnt[4] - cnt[1];
			cnt[2] = cnt[2] - cnt[5];
			N = cnt[0] + cnt[4] + cnt[2];
			if (N / 2 < cnt[0] || N / 2 < cnt[2] || N / 2 < cnt[4])  { printf("Case #%d: IMPOSSIBLE\n", ii); continue; }
			int tmp[3];
			tmp[0] = cnt[0];
			tmp[1] = cnt[2];
			tmp[2] = cnt[4];

			sort(tmp, tmp + 3);
			place(tmp[2], tmp[1], tmp[0], N);
			printf("Case #%d: ", ii);
			for (int i = 0; i < N; i++) {
				if (ans[i] == 'R' && cnt[3] != 0) {
					for (int k = 0; k < cnt[3]; k++) printf("RG");
					cnt[3] = 0;
				}
				if (ans[i] == 'B' && cnt[1] != 0) {
					for (int k = 0; k < cnt[1]; k++) printf("BO");
					cnt[1] = 0;
				}
				if (ans[i] == 'Y' && cnt[5] != 0) {
					for (int k = 0; k < cnt[5]; k++) printf("YV");
					cnt[5] = 0;
				}
				printf("%c", ans[i]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}