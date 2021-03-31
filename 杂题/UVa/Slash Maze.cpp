/*
UVa 707, Slash Maze
Retrieved from https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=105&page=show_problem&problem=646
Completed, By Gao Shuqi, on 2018-04-04
*/
#include <iostream>
#include <string.h>
#define N_MAX 150
using namespace std;

int W, H;
char map[N_MAX + 1][N_MAX + 1];
int dist[N_MAX + 1][N_MAX + 1];
bool visited[N_MAX + 1][N_MAX + 1];
int neighbor[][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
int max(int a, int b) { return (a > b) ? a : b; }

int traverse(int x, int y, int length) {
	visited[x][y] = true;
	dist[x][y] = length;
	int maxium=0;
	for (int i = 0; i < 8; i++) {
		int next_x = x + neighbor[i][0];
		int next_y = y + neighbor[i][1];
		if (next_x<1 || next_y<1 || next_x>H || next_y>W) continue;
		if (map[next_x][next_y] == '/' || map[next_x][next_y] == '\\') continue;
		if (visited[next_x][next_y] && dist[x][y] - dist[next_x][next_y]>1) return length;
		if (visited[next_x][next_y]) continue;
		int tmp = traverse(next_x, next_y, length + 1);
		if (tmp>0) return tmp;
	}
	return 0;
}

int main() {
	while (scanf("%d%d", &W, &H) != 0 && !(W == 0 && H == 0)) {
		W *= 2;
		H *= 2;
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= H; i += 2) {
			for (int j = 1; j <= W; j += 2) {
				char tmp;
				cin >> tmp;
				if (tmp == '/') { map[i][j + 1] = map[i + 1][j] = '/'; map[i][j] = map[i + 1][j + 1] = '.'; }
				if (tmp == '\\') { map[i][j + 1] = map[i + 1][j] = '.'; map[i][j] = map[i + 1][j + 1] = '\\'; }
			}
		}
		int maxium = 0;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (visited[i][j] || map[i][j] == '/' || map[i][j] == '\\') continue;
				maxium = max(maxium, traverse(i, j, 1));
			}
		}
		printf("%d\n", maxium);
	}
	return 0;
}