/*
Tongji Open Judge, Onsite 2017, Problem A. 网线布置
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1090
Finished, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int N;
struct E{
	int x;
	int y;
}dot[50000];

int dist[50000];
bool visited[50000];
int Min(int a, int b) { return (a < b) ? a : b; }
int getDistance(E a, E b) {return Min(abs(a.x - b.x), abs(a.y - b.y));}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		memset(dist, -1, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		int ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			dot[i].x = a;
			dot[i].y = b;
		}
		dist[0] = 0;
		int frontier = 0;
		visited[0] = true;
		for (int k = 1; k <= N - 1; k++) {
			for (int i = 0; i < N; i++) {
				if (visited[i]) continue;
				int dd = getDistance(dot[frontier], dot[i]);
				if (dist[i] == -1) dist[i] = dd;
				if (dist[i] != -1 && dist[i]>dist[frontier] + dd) dist[i] = dist[frontier] + dd;
			}
			int tmp = 0x7fffffff, pos;
			for (int i = 0; i < N; i++) {
				if (visited[i]) continue;
				if (dist[i] < tmp) { pos = i; tmp = dist[i]; }
			}
			visited[pos] = true;
			frontier = pos;
			ans += tmp;
		}
		printf("Case #%d:\n%d\n", ii, ans);
 	}
	return 0;
}
