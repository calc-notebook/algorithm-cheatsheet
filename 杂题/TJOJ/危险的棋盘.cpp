/*
Tongji OJ, Problem 1086. 危险的棋盘
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1086
By Gao Shuqi, on 2018-04-10
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int R, C;
char map[400][400], instr[400];
bool visited[400][400];

int Min(int a, int b) { return (a < b) ? a : b; }
int check(int, int);

int Travel(int x, int y, char c) {
	if (c == '^') {
		int i;
		for (i = x-1; i >= 1; i--) if (map[i][y] != '.') break;
		if (i == 0) return -1;
		return check(i, y);
	}
	else if (c == 'v') {
		int i;
		for (i = x+1; i <=R ; i++) if (map[i][y] != '.') break;
		if (i == R+1) return -1;
		return check(i, y);
	}
	else if (c == '>') {
		int i;
		for (i = y+1; i <= C; i++) if (map[x][i] != '.') break;
		if (i == C+1) return -1;
		return check(x, i);
	}
	else if (c == '<') {
		int i;
		for (i = y-1; i >= 1; i--) if (map[x][i] != '.') break;
		if (i == 0) return -1;
		return check(x, i);
	}
	return -1;
}

int check(int x, int y) {
	if (visited[x][y]) return 0;
	visited[x][y] = true;
	int ans=0x7fffffff;
	int tmp = Travel(x, y, map[x][y]);
	if (tmp != -1) ans=Min(ans, tmp);
	if (map[x][y] != '^') {
		tmp = Travel(x, y, '^');
		if (tmp != -1) ans = Min(ans, tmp+1);
	}
	else if (map[x][y] != 'v') {
		tmp = Travel(x, y, 'v');
		if (tmp != -1) ans = Min(ans, tmp + 1);
	}
	else if (map[x][y] != '>') {
		tmp = Travel(x, y, '>');
		if (tmp != -1) ans = Min(ans, tmp + 1);
	}
	else if (map[x][y] != '<') {
		tmp = Travel(x, y, '<');
		if (tmp != -1) ans = Min(ans, tmp + 1);
	}
	visited[x][y] = false;
	return (ans == 0x7fffffff) ? -1 : ans;
}

int main() {
	scanf("%d%d", &R, &C);
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= R; i++) {
		scanf("%s", instr);
		for (int j = 1; j <= C; j++)
			map[i][j] = instr[j - 1];
	}
	int cnt = 0x7fffffff;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == '.') continue;
			int tmp = check(i, j);
			if (tmp == -1) continue;
			cnt = Min(cnt, tmp);
		}
	}
	if (cnt == 0x7fffffff) cnt = -1;
	printf("%d", cnt);

	return 0;
}