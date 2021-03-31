#include <iostream>
#include <vector>
#include <string.h>
/*
Tongji OJ, Problem 1099. 不知道叫什么
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1099
图的遍历
Completed, By Gao Shuqi, on 2018-04-19.
*/

#include <algorithm>
#define N_MAX 100
using namespace std;

vector<int> G[N_MAX + 1];
int source[N_MAX + 1];
bool visited[N_MAX + 1];
int visit(int d) {
	int cnt = 1;
	for (int i = 0; i < G[d].size(); i++) {
		if (visited[G[d][i]]) continue;
		visited[G[d][i]] = true;
		cnt+=visit(G[d][i]);
	}
	return cnt;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) G[i].clear();
		for (int i = 1; i <= M; i++) scanf("%d", &source[i]);
		sort(source + 1, source + 1 + M);
		for (int i = 1; i <= N; i++) {
			int index, cnt;
			scanf("%d%d", &index, &cnt);
			if (cnt == 0) continue;
			for (int i = 0; i < cnt; i++){
				int tmp;
				scanf("%d", &tmp);
				G[index].push_back(tmp);
			}
		}
		int maxium = 0,poc=0;
		for (int i = 1; i <= M; i++) {
			memset(visited, 0, sizeof(visited));
			int tmp = visit(source[i])>maxium;
			if (tmp>maxium) { maxium = tmp; poc = source[i]; }
		}
		printf("Case #%d:\n",ii);
		printf("%d\n", poc);
	}

	return 0;
}