/*
Google Code Jam, Qualification Round 2014, Problem C. Minesweeper Master
Retrieved from https://code.google.com/codejam/contest/2974486/dashboard#s=p2
Finished, By Gao Shuqi, on 2018-03-25.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

char map[50][50];

int main() {

	freopen("C-small-practice.in", "r", stdin);
	freopen("C-small-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		int R, C, M;
		bool ans;
		scanf("%d%d%d", &R, &C, &M);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				map[i][j] = '.';
		}
		if (R*C <= M) ans = false;
		else if (R == 1) {
			ans = true;
			for (int i =1 ; i <= M; i++) map[0][i] = '*';
			map[0][C - 1] = 'c';
		}
		else if (C == 1) {
			ans = true;
			for (int i = 1; i <= M; i++) map[i][0] = '*';
			map[R-1][0] = 'c';
		}
		else if (C*R == M + 1) {
			ans = true;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					map[i][j] = '*';
			}
			map[R - 1][C - 1] = 'c';
		}
		else if ((R*(C - 2) >= M) && (M%R + 1 != R)) {
			ans = true;
			int cnt = 0;
			for (int i = 0; i < C && cnt<M; i++) {
				for (int j = 0; j < R && cnt<M; j++) {
					map[j][i] = '*';
					cnt++;
				}
			}
			map[R - 1][C - 1] = 'c';
		}
		else if ((C*(R - 2) >= M) && (M%C + 1 != C)) {
			ans = true;
			int cnt = 0;
			for (int i = 0; i < R && cnt<M; i++) {
				for (int j = 0; j < C && cnt<M; j++) {
					map[i][j] = '*';
					cnt++;
				}
			}
			map[R - 1][C - 1] = 'c';
		}
		else if ((C*(R - 2) < M) && (M - C*(R - 2)) % 2 == 0 && (R*C-M) >= 4) {
			ans = true;
			int cnt = 0;
			for (int i = 0; i < R-2 && cnt<M; i++) {
				for (int j = 0; j < C && cnt<M; j++) {
					map[i][j] = '*';
					cnt++;
				}
			}
			for (int i = 0; cnt < M; i++) { map[R - 2][i] = '*'; map[R - 1][i] = '*'; cnt += 2; }
			map[R - 1][C - 1] = 'c';
		}
		else if ((R*(C - 2) < M) && (M - R*(C - 2)) % 2 == 0 && (R*C-M) >= 4) {
			ans = true;
			int cnt = 0;
			for (int i = 0; i < C-2 && cnt<M; i++) {
				for (int j = 0; j < R && cnt<M; j++) {
					map[j][i] = '*';
					cnt++;
				}
			}
			for (int i = 0; cnt < M; i++) { map[i][C-2] = '*'; map[i][C-1] = '*'; cnt += 2; }
			map[R - 1][C - 1] = 'c';
		}
		else{
			ans = false;
		}
		if (ans) {
			printf("Case #%d:\n", ii);
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					printf("%c", map[i][j]);
				printf("\n");
			}
		}
		else printf("Case #%d: Impossible\n", ii);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}