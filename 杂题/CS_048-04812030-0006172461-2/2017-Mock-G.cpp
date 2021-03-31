#include <iostream>
#include <vector>
#define N_MAX 101
using namespace std;

class Node{
public:
	int owner_level;
	int item_price;
};

class Edge{
public:
	int discount;
	int item_ID;
};

Node item[N_MAX];
vector<Edge> edge[N_MAX];
int M;

int min(int a, int b) { return (a > b) ? b : a; }
int max(int a, int b) { return (a > b) ? a : b; }

int DFS(int root, int pre_cost, int low_level, int high_level){
	if (edge[root].empty()) return pre_cost;
	int min_cost = pre_cost;
	for (int idx = 0; idx < edge[root].size(); idx++){
		int _low_level = min(item[edge[root][idx].item_ID].owner_level, low_level);
		int _high_level = max(item[edge[root][idx].item_ID].owner_level, high_level);
		if (_high_level - _low_level > M) continue;
		else{
			high_level = _high_level;
			low_level = _low_level;
		}
		int local_cost = DFS(edge[root][idx].item_ID, item[edge[root][idx].item_ID].item_price, low_level, high_level);
		min_cost = min(min_cost, edge[root][idx].discount + local_cost);
	}
	return min_cost;
}

int main(){
	int N;
	scanf("%d%d", &M, &N);
	for (int idx1 = 1; idx1 <= N; idx1++){
		int x;
		scanf("%d%d%d", &item[idx1].item_price,&item[idx1].owner_level, &x);
		for (int idx2 = 0; idx2 < x; idx2++){
			Edge newEdge;
			scanf("%d%d", &newEdge.item_ID,&newEdge.discount);
			edge[idx1].push_back(newEdge);
		}
	}
	int answer = DFS(1, item[1].item_price, item[1].owner_level, item[1].owner_level);
	printf("%d\n", answer);
	getchar();
	getchar();
	return 0;
}