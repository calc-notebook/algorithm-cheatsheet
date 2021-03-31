#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

const int N_MAX = 100;

int dist[N_MAX][N_MAX];
bool vis[N_MAX];
int edge[N_MAX];
int N;

int Prime()
{
	memset(vis, 0, sizeof(bool)* N);
	vis[0] = true;
	for (int i = 0; i < N - 1; i++)
	{
		int m = INT_MAX;
		int id = 0;
		for (int j = 0; j < N; j++)
		{
			if (!vis[j] && dist[0][j] < m)
			{
				m = dist[0][j];
				id = j;
			}
		}
		vis[id] = true;
		edge[i] = m;
		for (int j = 0; j < id; j++)
		{
			if (!vis[j] && dist[0][j] > dist[j][id]) dist[0][j] = dist[j][id];
		}
		for (int j = id + 1; j < N; j++)
		{
			if (!vis[j] && dist[0][j] > dist[id][j]) dist[0][j] = dist[id][j];
		}
	}
	int total_cost = 0;
	for (int i = 0; i < N - 1; i++) total_cost += edge[i];
	return total_cost;
}

int main()
{
	while (scanf("%d", &N) != EOF & N != 0){
		for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &dist[i][j]);
		}
		printf("%d\n", Prime());
	}
	return 0;
}