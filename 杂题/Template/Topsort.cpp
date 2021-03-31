#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N_MAX = 500 + 1;

vector<int> edges[N_MAX];
queue<int> q;
int in[N_MAX];
int n, m;

bool topsort(){
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i++)
	if (in[i] == 0)
		q.push(i);
	int cnt_of_processed = 0;
	while (!q.empty()){
		int cur_point = q.front(); q.pop(); cnt_of_processed++;
		for (int i = 0; i < edges[cur_point][i].size(); i++){
			in[edges[cur_point][i]]--;
			if (in[edges[cur_point][i]] == 0) q.push(edges[cur_point][i]);
		}
	}
	return cnt_of_processed == n;
}

int main(){
	while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)){
		for (int i = 0; i < n; i++){ in[i] = 0; edges[i].clear(); }
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			in[b]++;
			edges[a].push_back(a);
		}
		bool answer = topsort();
		if (answer) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}