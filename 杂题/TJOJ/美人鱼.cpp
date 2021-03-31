/*
Tongji OJ, Problem 1003. 美人鱼
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1003
单源最短路径, DFS.
Completed, By Gao Shuqi, on 2018-04-09
*/
#include <iostream>
#include <vector>
#define N_MAX 1000
using namespace std;

struct Edge{
	int end;
	int cost;
};
vector<Edge> edge[N_MAX + 1];
int dist[N_MAX+1];
bool visited[N_MAX + 1];
int n, m;
int S, T;
int cnt;
int dist_mini;

void visit(int d, int depth) {
	if (d == T && depth <= dist_mini + 1) { cnt++; return; }
	if (depth > dist_mini + 1) return;
	for (int j = 0; j < edge[d].size(); j++) {
		visit(edge[d][j].end, depth + edge[d][j].cost);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Edge tmp;
		tmp.end = b;
		tmp.cost = c;
		edge[a].push_back(tmp);
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		dist[i] = -1; 
		visited[i] = false;
	}
	scanf("%d%d", &S, &T);
	int frontier = S;
	dist[frontier]=0;
	visited[frontier] = true;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edge[frontier].size(); j++) {
			if (visited[edge[frontier][j].end]) continue;
			if (dist[edge[frontier][j].end] == -1) { dist[edge[frontier][j].end] = dist[frontier] + edge[frontier][j].cost; }
			if (dist[edge[frontier][j].end]!=-1 && dist[edge[frontier][j].end] > dist[frontier] + edge[frontier][j].cost) { dist[edge[frontier][j].end] = dist[frontier] + edge[frontier][j].cost; }
		}
		int minium = 0x7fffffff, poc;
		for (int j = 1; j <= n; j++) {
			if (dist[j] == -1 || visited[j]) continue;
			if (dist[j] < minium) { minium = dist[j]; poc = j; }
		}
		frontier = poc;
		visited[poc] = true;
	}
	dist_mini = dist[T];
	visit(S, 0);
	printf("%d", cnt);
	getchar();
	getchar();
	return 0;
}