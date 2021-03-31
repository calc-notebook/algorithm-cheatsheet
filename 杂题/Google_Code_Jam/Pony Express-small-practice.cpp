/*
Google Code Jam, Round 1B 2017. Problem C. Pony Express
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard#s=p2
动态规划
Completed, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#define N_MAX 100
using namespace std;

int N, Q;
struct City{
	int E, S;
}city[N_MAX+1];

int map[N_MAX + 1][N_MAX + 1];
int U[100], V[100];

double min(double a, double b) { return (a < b) ? a : b; }

int main() {
	freopen("C-small-practice.in", "r", stdin);
	freopen("C-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &N, &Q);
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &city[i].E, &city[i].S);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);
		}
		for (int k = 0; k < Q; k++) scanf("%d%d", &U[k], &V[k]);
		printf("Case #%d:", ii);
		for (int k = 0; k < Q; k++) {
			double ans;
			//计算U[k]到V[k]的最小时间开销，并赋值给ans
			double dp[N_MAX + 1];
			dp[N] = 0;
			for (int i = N - 1; i >= 1; i--) {
				double minium = -1;
				double dist = map[i][i+1];
				for (int j = i + 1; j<=N && dist <= city[i].E; j++) {
					if (minium == -1) minium = dp[j] + dist / city[i].S;
					else minium = min(minium, dp[j] + dist / city[i].S);
					if (j == N) break;
					dist += map[j][j + 1];
				}
				dp[i] = minium;
			}
			ans = dp[1];
			printf(" %.8f", ans);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}