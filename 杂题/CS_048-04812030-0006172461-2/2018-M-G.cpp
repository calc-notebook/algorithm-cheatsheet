#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

const int MAX_VEC = 501;
struct Pos
{
	int x, y;
};

float gra[MAX_VEC][MAX_VEC];
Pos pos[MAX_VEC];
float dist[MAX_VEC];
bool vis[MAX_VEC];

int N, S, P;

float Prime()
{
	memset(vis, 0, sizeof(bool)* P);
	vis[0] = true;
	for (int i = 0; i < P - 1; i++)
	{
		float m = (float)INT_MAX;
		int id = 0;
		for (int j = 0; j < P; j++)
		{
			if (!vis[j] && gra[0][j] < m)
			{
				m = gra[0][j];
				id = j;
			}
		}
		vis[id] = true;
		dist[i] = m;
		for (int j = 0; j < id; j++)
		{
			if (!vis[j] && gra[0][j] > gra[j][id]) gra[0][j] = gra[j][id];
		}
		for (int j = id + 1; j < P; j++)
		{
			if (!vis[j] && gra[0][j] > gra[id][j]) gra[0][j] = gra[id][j];
		}
	}
	sort(dist, dist + P - 1);
	return dist[P - 1 - S];
}

int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d", &S, &P);
		for (int i = 0; i < P; i++)
		{
			scanf("%d %d", &pos[i].x, &pos[i].y);
		}
		for (int i = 0; i < P; i++)
		{
			for (int j = i + 1; j < P; j++)
			{
				float a = float(pos[i].x - pos[j].x);
				float b = float(pos[i].y - pos[j].y);
				gra[i][j] = sqrtf(a*a + b*b);
			}
		}
		printf("%.2f\n", Prime());
	}
	return 0;
}
