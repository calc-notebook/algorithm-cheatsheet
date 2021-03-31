/*
Tongji OJ, Problem 1002. 正方形
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1002
动态规划问题
Completed, By Gao Shuqi, on 2018-04-09
*/
#include <iostream>
#define N_MAX 1000
using namespace std;

int n, m;
bool map[N_MAX + 1][N_MAX + 1], visited[N_MAX + 1][N_MAX + 1];

int min(int a, int b) { return (a < b) ? a : b; }
int dp[N_MAX + 1][N_MAX+1];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			int tmp;
			scanf("%d", &tmp);
			map[i][j] = (tmp == 1) ? true : false;
		}
	}
	int maxium=0;
	for (int i = 1; i <= n; i++) { dp[i][1] = (map[i][1]) ? 1 : 0; }
	for (int i = 1; i <= m; i++) { dp[1][i] = (map[1][i]) ? 1 : 0; }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!map[i][j]) {dp[i][j] = 0; continue;}
			if (dp[i][j - 1] != dp[i - 1][j]) dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
			else {
				if (dp[i - 1][j - 1] >= dp[i][j - 1]) dp[i][j] = dp[i][j - 1] + 1;
				else dp[i][j] = dp[i][j - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] > maxium) maxium = dp[i][j];
		}
	}
	printf("%d", maxium);
	return 0;
}