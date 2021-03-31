/*
Variance of the Single-Source Shortest Paths Problem.
Complted, By Gao Shuqi, on 2018-04-03.
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#define N_MAX 100
using namespace std;

struct Edge{
	int end;
	int capacity;
};
int N, R;
int S, D, T;
vector<Edge> city[N_MAX + 1];
int cap[N_MAX + 1];
bool visited[N_MAX + 1];

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int main() {
	while (scanf("%d%d", &N, &R) != EOF && !(N == 0 && R == 0)) {
		for (int i = 0; i < R; i++) {
			Edge tmp;
			int C1, C2, P;
			scanf("%d%d%d", &C1, &C2, &P);
			tmp.capacity = P;
			tmp.end = C2;
			city[C1].push_back(tmp);
			tmp.end = C1;
			city[C2].push_back(tmp);
		}
		memset(cap, 0, sizeof(cap));
		memset(visited, 0, sizeof(visited));
		scanf("%d%d%d", &S, &D, &T);
		cap[S] = 0x7fffffff;
		visited[S] = true;
		int frontier = S;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < city[frontier].size(); j++) {
				int e = city[frontier][j].end;
				if (visited[e]) continue;
				cap[e] = max(cap[e], min(cap[frontier], city[frontier][j].capacity));
			}
			int maxium=0, poc;
			for (int j = 1; j <= N; j++) {
				if (visited[j]) continue;
				if (cap[j]>maxium) { maxium = cap[j]; poc = j; }
			}
			frontier = poc;
			visited[frontier] = true;
		}
		printf("%d\n", (T+cap[D]-1)/ cap[D]);
	}
	return 0;
}