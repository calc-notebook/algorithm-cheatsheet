/*
Tongji OJ, Problem 1001. 染色
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1001
回溯法
Completed, By Gao Shuqi, on 2018-04-09
*/
#include <iostream>
#include <vector>
#include <string.h>
#define N_MAX 10
using namespace std;

struct Dot{
	int end;
};

vector<Dot> dot[N_MAX + 1];
int color[N_MAX + 1],cnt;
int n, m; /* n: the number of vertices, m: the number of edges */

void paint(int depth) {
	int p;
	for (p = 1; p <= n && color[p]!=0; p++);
	if (p > n) return; /* could never run */
	for (int c = 1; c <= 4; c++) {
		bool avaible = true;
		for (int i = 0; i < dot[p].size(); i++) {
			if (color[dot[p][i].end] == c) { avaible = false; break; }
		}
		if (!avaible) continue;
		color[p] = c;
		if (depth == n) { cnt++; color[p] = 0; continue; }
		paint(depth + 1);
		color[p] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Dot tmp;
		tmp.end = a;
		dot[b].push_back(tmp);
		tmp.end = b;
		dot[a].push_back(tmp);
	}
	cnt = 0;
	paint(1);
	printf("%d", cnt);

	return 0;
}