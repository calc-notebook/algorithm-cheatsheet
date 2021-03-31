/*
Google Code Jam, Qualification Round 2013, Problem A. Tic-Tac-Toe-Tomek
Retrieved from https://code.google.com/codejam/contest/2270488/dashboard
Finished, By Gao Shuqi, on 2018-03-27.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

char map[4][4];
int Min(int a, int b) { return (a < b) ? a : b; }

bool isFull() {
	int cnt = 0;
	for (int i = 0; i < 4;i++)
	for (int j = 0; j < 4;j++)
	if (map[i][j] == '.') cnt++;
	return cnt == 0;
}

int checkRow() {
	int cnt_X, cnt_O;
	for (int i = 0; i < 4; i++) {
		cnt_X = 0;
		cnt_O = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 'X') cnt_X++;
			if (map[i][j] == 'O') cnt_O++;
			if (map[i][j] == 'T') { cnt_X++; cnt_O++; }
		}
		if (cnt_X == 4) return 1;
		if (cnt_O == 4) return -1;
	}
	return 0;
}

int checkCol() {
	int cnt_X, cnt_O;
	for (int j = 0; j < 4; j++) {
		cnt_X = 0;
		cnt_O = 0;
		for (int i = 0; i < 4; i++) {
			if (map[i][j] == 'X') cnt_X++;
			if (map[i][j] == 'O') cnt_O++;
			if (map[i][j] == 'T') { cnt_X++; cnt_O++; }
		}
		if (cnt_X == 4) return 1;
		if (cnt_O == 4) return -1;
	}
	return 0;
}

int checkDiag1() {
	int cnt_X=0, cnt_O=0;
	for (int i = 0; i < 4;i++) {
		int j = i;
		if (map[i][j] == 'X') cnt_X++;
		if (map[i][j] == 'O') cnt_O++;
		if (map[i][j] == 'T') { cnt_X++; cnt_O++; }
	}
	if (cnt_X == 4) return 1;
	if (cnt_O == 4) return -1;
	return 0;
}

int checkDiag2() {
	int cnt_X = 0, cnt_O = 0;
	for (int i = 0; i < 4; i++) {
		int j = 3-i;
		if (map[i][j] == 'X') cnt_X++;
		if (map[i][j] == 'O') cnt_O++;
		if (map[i][j] == 'T') { cnt_X++; cnt_O++; }
	}
	if (cnt_X == 4) return 1;
	if (cnt_O == 4) return -1;
	return 0;
}


int main() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		for (int i = 0; i < 4; i++) {
			char str[5];
			scanf("%s", str);
			for (int j = 0; j < 4; j++)
				map[i][j] = str[j];
		}
		int ans;
		int a = checkRow();
		int b = checkCol();
		int c = checkDiag1();
		int d = checkDiag2();
		if (a == 1 || b == 1 || c ==1 || d == 1) printf("Case #%d: X won\n", ii); // X won
		else if (a == -1 || b == -1 || c == -1 || d == -1) printf("Case #%d: O won\n", ii);
		else if (isFull()) printf("Case #%d: Draw\n", ii);
		else printf("Case #%d:  Game has not completed\n", ii);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}