#include <iostream>
#include <algorithm>
#include <cstring>
#define N_MAX 101
using namespace std;

class Edge{
public:
	int head;
	int tail;
	int cost;
};

Edge edges[N_MAX*(N_MAX - 1) / 2];
int root[N_MAX];
int n, m;

bool cmp(Edge left, Edge right) { return (left.cost < right.cost); }
int max(int a, int b) { return (a > b) ? a : b; }

int getRoot(int idx){
	if (root[idx] == -1) return idx;
	int trueRoot = getRoot(root[idx]);
	root[idx] = trueRoot;
	return trueRoot;
}

int Kruskal(){
	sort(edges, edges + m, cmp);
	int max_edge_cost = 0;	for (int idx = 1; idx <= n; idx++) root[idx] = -1;

	int cur_edge_index = 0;
	int total_cost = 0;
	for (int p = 1; p <= n - 1; p++){
		for (; getRoot(edges[cur_edge_index].head) == getRoot(edges[cur_edge_index].tail); cur_edge_index++);
		int a = getRoot(edges[cur_edge_index].head);
		int b = getRoot(edges[cur_edge_index].tail);
		root[a] = b;
		total_cost += edges[cur_edge_index].cost;
		cur_edge_index++;
	}
	return total_cost;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int idx = 0; idx < m; idx++){
			scanf("%d%d%d", &edges[idx].head, &edges[idx].tail, &edges[idx].cost);
		}
		int cost = Dijkstra();
		printf("%d\n", cost);
	}
	return 0;
}
