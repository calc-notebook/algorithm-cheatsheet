#include <iostream>
#include <vector>
#include <cstring>
#define N_MAX 200
using namespace std;

int N, F, D;
vector<int> dishes[N_MAX], drinks[N_MAX];

int max(int a, int b) { return (a > b) ? a : b; }

int process(bool* dishes_used, bool* drinks_used, int start){
	if (start == N - 1){
		for (int u = 0; u < dishes[start].size();u++)
		for (int v = 0; v < drinks[start].size(); v++){
			int a = dishes[start][u];
			int b = drinks[start][v];
			if (!(dishes_used[a] || drinks_used[b])) return 1;
		}
		return 0;
	}
	int answer = process(dishes_used, drinks_used, start + 1);
	for (int u = 0; u < dishes[start].size(); u++){
		for (int v = 0; v < drinks[start].size(); v++){
			int a = dishes[start][u];
			int b = drinks[start][v];
			if (dishes_used[a] || drinks_used[b]) continue;
			dishes_used[a] = true;
			drinks_used[b] = true;
			answer = max(answer, 1+ process(dishes_used, drinks_used, start + 1));
			dishes_used[a] = false;
			drinks_used[b] = false;
		}
	}
	return answer;
}

int main(){
	scanf("%d%d%d", &N, &F, &D);
	for (int idx = 0; idx < N; idx++) {
		int u, v;
		scanf("%d%d", &u, &v);
		for (int p = 0; p < u; p++){
			int t;
			scanf("%d", &t);
			dishes[idx].push_back(t);
		}
		for (int p = 0; p < v; p++){
			int t;
			scanf("%d", &t);
			drinks[idx].push_back(t);
		}
	}

	/* process */
	bool dishes_used[N_MAX], drinks_used[N_MAX];
	memset(dishes_used, false, sizeof(dishes_used));
	memset(drinks_used, false, sizeof(drinks_used));
	int answer=process(dishes_used,drinks_used,0);
	printf("%d\n", answer);
	
	getchar();
	getchar();

	return 0;
}