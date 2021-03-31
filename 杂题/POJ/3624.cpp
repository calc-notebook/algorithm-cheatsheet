#include <iostream>
#include <limits.h>
using namespace std;

const int W_MAX = 12880 + 1;
const int N_MAX = 3402;
const int MAX_INT = 1e10;

int W, N;
int w[N_MAX], v[N_MAX];

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int knapsack_min(){
	int dp[W_MAX]; dp[0] = 0; for (int i = 1; i <= W; i++) dp[i] = MAX_INT;
	for (int p = 0; p < N; p++)
	for (int i = w[p]; i <= W; i++)
		dp[i] = min(dp[i], dp[i - w[p]] + v[p]);
	if (dp[W] == MAX_INT) return -1;
	else return dp[W];
}

int knapsack_01_min(){
	int dp[W_MAX]; dp[0] = 0; for (int i = 1; i <= W; i++) dp[i] = MAX_INT;
	for (int p = 0; p < N; p++)
	for (int i = W; i >= w[p]; i--)
		dp[i] = min(dp[i], dp[i - w[p]] + v[p]);
	if (dp[W] == MAX_INT) return -1;
	else return dp[W];
}

int knapsack_max(){
	int dp[W_MAX]; dp[0] = 0; for (int i = 1; i <= W; i++) dp[i] = 0;
	for (int p = 0; p < N; p++)
	for (int i = w[p]; i <= W; i++)
		dp[i] = max(dp[i], dp[i - w[p]] + v[p]);
	return dp[W];
}

int knapsack_01_max(){
	int dp[W_MAX]; dp[0] = 0; for (int i = 1; i <= W; i++) dp[i] = 0;
	for (int p = 0; p < N; p++)
	for (int i = W; i >= w[p]; i--)
		dp[i] = max(dp[i], dp[i - w[p]] + v[p]);
	return dp[W];
}

int main(){
	while (scanf("%d%d", &N, &W) != EOF /*&& !(N==0 && W==0)*/){
		for (int i = 0; i < N; i++) scanf("%d%d", &w[i], &v[i]);
		int answer = knapsack_01_max();
		printf("%d\n", answer);
	}
	return 0;
}