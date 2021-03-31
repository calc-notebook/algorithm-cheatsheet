#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define N_MAX 1000
using namespace std;

class Edge{
public:
	int tail;
	int isSame;
};

vector<Edge> edges[N_MAX];
int label[N_MAX];
int n, m; // n - the number of butterfly, m - the number of relations

bool process(){
	for (int p = 0; p < n; p++){
		if (label[p] != -1) continue;
		label[p] = 0;
		queue<int> waitzone;
		waitzone.push(p);
		while (!waitzone.empty()){
			int start = waitzone.front(); waitzone.pop();
			for (int idx = 0; idx < edges[start].size(); idx++){
				int next = edges[start][idx].tail;
				int relation = edges[start][idx].isSame;
				if (label[next] == -1) {
					label[next] = (label[start] + relation) % 2;
					waitzone.push(next);
				}
				else{
					if (label[next] != (label[start] + relation) % 2) return false;
				}
			}
		}
	}
	return true;
}

int main(){
	while (scanf("%d%d", &n, &m) != EOF){
		memset(label, -1, N_MAX);
		for (int idx = 0; idx < n; idx++) edges[idx].clear();
		for (int idx = 0; idx < m; idx++){
			int a, b;
			Edge addedEdge;
			scanf("%d%d%d", &a, &b, &addedEdge.isSame);
			addedEdge.tail = b; edges[a].push_back(addedEdge);
			addedEdge.tail = a; edges[b].push_back(addedEdge);
		}
		bool flag = process();
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}