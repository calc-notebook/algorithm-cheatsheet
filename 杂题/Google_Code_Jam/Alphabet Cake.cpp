/*
Google Code Jam, Round 1A 2017, Problem A. Alphabet Cake
Retrieved from https://code.google.com/codejam/contest/5304486/dashboard#s=p1
分治法
By Gao Shuqi, on 2018-04-11.
*/

#include <iostream>
#define N_MAX 25
using namespace std;

int R, C;
char map[N_MAX + 1][N_MAX + 1];
int cnt[N_MAX + 1];
int mark[N_MAX + 1],poc;

void fill(int left, int right, int top, int bottom, char c) {
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			map[i][j] = c;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &R, &C);
		for (int i = 1; i <= R; i++) {
			int tmp = 0;
			for (int j = 1; j <= C; j++) {
				cin >> map[i][j];
				if (map[i][j] != '?') tmp++;
			}
			cnt[i] = tmp;
		}
		int last_row = R;
		for (; last_row > 0 && cnt[last_row] == 0; last_row--);
		int current_row = 1;
		while (current_row <= R) {
			int tmp = current_row;
			for (; current_row <= R && cnt[current_row] == 0; current_row++);
			poc = 0;
			for (int i = 1; i <= C; i++) {
				if (map[current_row][i] != '?') mark[++poc] = i;
			}
			int bottom = (current_row == last_row) ? R : current_row;
			if (cnt[current_row] == 1) fill(1, C, tmp, bottom, map[current_row][mark[1]]);
			else fill(1, mark[2]-1, tmp, bottom, map[current_row][mark[1]]);
			for (int i = 1; i < cnt[current_row]; i++) {
				int right = (i == cnt[current_row] - 1) ? C : mark[i + 1] - 1;
				fill(mark[i] + 1, right, tmp, bottom, map[current_row][mark[i]]);
			}
			if (bottom = R) break;
			current_row++;
		}
		printf("Case #%d:\n", ii);
		for (int i = 1; i <= R; i++){
			printf("%c", map[i][1]);
			for (int j = 2; j <= C; j++)
				printf(" %c", map[i][j]);
			printf("\n");
		}
	}
	return 0;
}