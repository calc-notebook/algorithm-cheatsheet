#include <iostream>
#include <cstring>
#include <queue>

#define N_MAX 100001
using namespace std;



bool visited[N_MAX];
int cost[N_MAX];

/* Dynamic Processing */
int catchCows_dp(int person, int cow){
	memset(visited, 0, sizeof(visited));
	memset(cost, -1, sizeof(cost));

	cost[person] = 0;
	visited[person] = true;

	bool finished = false;
	while (!finished)
	{
		finished = true;
		for (int idx = 0; idx<N_MAX; idx++){
			if (!visited[idx]) { finished = false; continue; }
			if (idx != 0) { if (cost[idx - 1] == -1 || cost[idx - 1]>cost[idx] + 1) cost[idx - 1] = cost[idx] + 1; visited[idx - 1] = true; }
			if (idx != N_MAX) { if (cost[idx + 1] == -1 || cost[idx + 1]>cost[idx] + 1) cost[idx + 1] = cost[idx] + 1; visited[idx + 1] = true; }
			if (idx * 2 <= N_MAX) { if (cost[idx * 2] == -1 || cost[idx * 2]>cost[idx] + 1) cost[idx * 2] = cost[idx] + 1; visited[idx * 2] = true; }
		}
	}

	return cost[cow];
}

/* Breadth-First e */
int catchCows_bfs(int person, int cow){
	memset(visited, 0, sizeof(visited));
	memset(cost, -1, sizeof(cost));

	queue<int> waitzone;
	while (!waitzone.empty()) waitzone.pop();

	waitzone.push(person);
	visited[person] = true;
	cost[person] = 0;
	while (!waitzone.empty() && !visited[cow]){
		int curPos = waitzone.front();
		waitzone.pop();
		
		if (curPos < N_MAX-1 && !visited[curPos + 1]) {
			visited[curPos + 1] = true;
			cost[curPos + 1] = cost[curPos] + 1;
			waitzone.push(curPos + 1);
		}
		if (curPos > 0 && !visited[curPos - 1]) {
			visited[curPos - 1] = true;
			cost[curPos - 1] = cost[curPos] + 1;
			waitzone.push(curPos - 1);
		}
		if (curPos * 2 < N_MAX && !visited[curPos * 2]) {
			visited[curPos * 2] = true;
			cost[curPos * 2] = cost[curPos] + 1;
			waitzone.push(curPos * 2);
		}
	}
	return cost[cow];
}

int main(){
	int N, K;
	cin >> N >> K;
	int answer;
	answer=catchCows_bfs(N, K);
	printf("%d\n", answer);
	return 0;
}
