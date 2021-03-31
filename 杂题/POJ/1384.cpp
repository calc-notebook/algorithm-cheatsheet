#include <iostream>
#include <limits.h>
using namespace std;

const int W_MAX = 10000 + 1;
const int N_MAX = 500;
const int MAX_INT = 1e10;

int W, N;
int w[N_MAX], v[N_MAX];

int min(int a, int b) { return (a < b) ? a : b; }

int dp(){
	int dp[W_MAX]; dp[0] = 0; for (int i = 1; i <= W; i++) dp[i] = MAX_INT;
	for (int p = 0; p < N; p++)
	for (int i = w[p]; i <= W; i++)
		dp[i] = min(dp[i], dp[i - w[p]] + v[p]);
	if (dp[W] == MAX_INT) return -1;
	else return dp[W];
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int E, F;
		scanf("%d%d", &E, &F);
		W = F - E;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d%d", &v[i], &w[i]);
		int answer = dp();
		if (answer == -1) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", answer);
	}
	return 0;
}