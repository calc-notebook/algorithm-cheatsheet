/*
Tongji Open Judge, Onsite 2017, Problem B. 打发时间
Retrieved from http://acm.tongji.edu.cn/problem.php?cid=1003&pid=1
Finished, By Gao Shuqi, on 2018-03-27.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int R, C;
char map[1001][1001];
bool visited[1001][1001];
int neighbor[][2] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { -1,0 }, { 1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };

void FloodFill(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int next_x = x + neighbor[i][0];
		int next_y = y + neighbor[i][1];
		if (next_x<1 || next_x >R || next_y <1 || next_y>C) continue;
		if (visited[next_x][next_y] || map[next_x][next_y] == '.') continue;
		visited[next_x][next_y] = true;
		FloodFill(next_x, next_y);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &R, &C);
		for (int i = 1; i <= R; i++) {
			char str[1000];
			scanf("%s", str);
			for (int j = 1; j <= C; j++) map[i][j] = str[j - 1];
		}
		memset(visited, 0, sizeof(visited));
		int cnt_A=0, cnt_C=0, cnt_M=0, cnt_T=0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (visited[i][j] || map[i][j] == '.') continue;
				visited[i][j] = true;
				FloodFill(i, j);
				cnt_T++; //
			}
		}
		printf("Case #%d:\nTotal=%d\n", ii, cnt_T);
	}
	return 0;
}