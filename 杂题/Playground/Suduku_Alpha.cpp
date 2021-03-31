/*
Standard Suduku Solver
input: the given values and corresponding coordinations
ouput: the finished Suduku
the index start from the top/left to the bottom/right
input 0 0 0 means the end of given values input and start the calcualtion
input -1 -1 -1 quit the program
By Gao Shuqi, on 2018-03-25.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int map[10][10], v, x, y;
bool fix[10][10], col[10][10], row[10][10], square[10][10], diag[3][10];
//int cnt = 0;
void next(int m, int n, int &next_m, int &next_n) {
	if (n < 9) {
		next_n = n + 1;
		next_m = m;
		return;
	}
	else {
		next_n = 1;
		next_m = m + 1;
		return;
	}
}
bool fillBlank(int m, int n) {
	//cnt++;
	//if (cnt % 100000 == 0) printf("Try %d: %d %d\n", cnt, m, n);
	int next_m, next_n;
	if (fix[m][n] && !(m == 9 && n == 9)) {
		next(m, n, next_m, next_n);
		bool flag=fillBlank(next_m, next_n);
		return flag;
	}
	if (fix[m][n] && m == 9 && n == 9) {
		return true;
	}
	if (m == 9 && n == 9) {
		for (int k = 1; k <= 9; k++) {
			if (col[9][k] || row[9][k] || square[9][k] || diag[1][k]) continue;
			map[9][9] = k;
			return true;
		}
		return false;
	}
	for (int k = 1; k <= 9; k++) {
		if (col[n][k] || row[m][k] || square[3*((m+2)/3-1)+(n+2)/3][k]) continue;
		if (m == n && diag[1][k]) continue;
		if (m + n == 10 && diag[2][k]) continue;
		map[m][n] = k;
		col[n][k] = row[m][k] = square[3 * ((m + 2) / 3 - 1) + (n + 2) / 3][k] = true;
		if (m == n) diag[1][k] = true;
		if (m + n == 10) diag[2][k] = true;
		next(m, n, next_m, next_n);
		bool flag = fillBlank(next_m, next_n);
		if (flag) return flag;
		col[n][k] = row[m][k] = square[3 * ((m + 2) / 3 - 1) + (n + 2) / 3][k] = false;
		if (m == n) diag[1][k] = false;
		if (m + n == 10) diag[2][k] = false;
		map[m][n] = 0;
	}
	return false;
}

int main() {
	freopen("practice.in", "r", stdin);
	freopen("practice.out", "w", stdout);
	while (scanf("%d %d %d", &x, &y, &v) != EOF) {
//input
		if (v == -1 && x == -1 && y == -1) break;
		if (x != 0 && y != 0) {
			col[y][v] = row[x][v] = square[3 * ((x + 2) / 3 - 1) + (y + 2) / 3][v] = true;
			if (x == y) diag[1][v] = true;
			if (x + y == 10) diag[2][v] = true;
			map[x][y] = v;
			fix[x][y] = true;
			continue;
		}
//precess
		bool finish=fillBlank(1, 1);
//display the Suduku
		printf("-----------------\n");
		if (finish) {
			for (int i = 1; i <= 9; i++) {
				printf("%d", map[i][1]);
				for (int j = 2; j <= 9; j++) {
					printf(" %d", map[i][j]);
				}
				printf("\n");
			}
		}
		else
			printf("No solution!\n");
		printf("-----------------\n");
//clear the workspace, prepare for the next round
		memset(map, 0, sizeof(map));
		memset(fix, 0, sizeof(fix));
		memset(row, 0, sizeof(fix));
		memset(col, 0, sizeof(fix));
		memset(square, 0, sizeof(fix));
		memset(diag, 0, sizeof(fix));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}