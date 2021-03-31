/*
Graph Searching, Easy.
Completed, By Gao Shuqi, on 2018-04-03.
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#define N_MAX 200
using namespace std;

int N; /* the number of vertical */
struct Edge{
	int end;
};
vector<Edge> edge[N_MAX];
int color[N_MAX];

bool cal(int d) {
	for (int i = 0; i < edge[d].size(); i++) {
		int b = edge[d][i].end;
		if (color[b] == -1) {
			color[b] = 1 - color[d];
			bool flag = cal(b);
			if (!flag) return false;
		}
		else if (color[b] != color[d]) continue;
		else return false;
	}
	return true;
}

int main() {
	while (scanf("%d",&N) != EOF && N != 0) {
		int l;
		scanf("%d", &l);
		for (int i = 0; i < l; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			Edge tmp;
			tmp.end = b;
			edge[a].push_back(tmp);
			tmp.end = a;
			edge[b].push_back(tmp);
		}
		memset(color, -1, sizeof(color));
		bool flag;
		for (int i = 0; i < N; i++) {
			if (color[i] != -1) continue;
			color[i] = 0;
			flag=cal(i);
			if (!flag) break;
		}
		if (flag) printf("BICOLORABLE\n");
		else printf("NOT BICOLORABLE\n");
	}
	return 0;
}