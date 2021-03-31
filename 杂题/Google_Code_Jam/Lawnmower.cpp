/*
Google Code Jam, Qualification Round 2013, Problem B. Lawnmower
Retrieved from https://code.google.com/codejam/contest/2270488/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-03-27.
*/

#include <iostream>
using namespace std;
int map[101][101], N, M;

int Min(int a, int b) { return (a < b) ? a : b; }
bool checkHeight(int x, int y) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = Min(map[i][y], map[x][j]);
			if (map[i][j] != tmp) return false;
		}
	}
	return true;
}

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++){
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++)
				scanf("%d", &map[i][j]);
		}
		int maxium = 0, cnt_max = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] > maxium) { maxium = map[i][j]; cnt_max = 0; }
				if (map[i][j] == maxium) { cnt_max++; }
			}
		}
		bool tmp;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] != maxium) continue;
				tmp = checkHeight(i, j);
				if (!tmp) break;
			}
		}
		if (tmp) printf("Case #%d: YES\n", ii);
		else printf("Case #%d: NO\n", ii);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}