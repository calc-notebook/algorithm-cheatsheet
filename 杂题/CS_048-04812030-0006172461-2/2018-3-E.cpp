//
// Source: http://algorithm.openjudge.cn/2018test3/E/
// Type: Dynamic Programming
// Solved by Sukie on 11/18/2018.
//
#include <iostream>
#define N_MAX 100000
using namespace std;

int max(int a, int b){ return (a > b) ? a : b; }

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		int prices[N_MAX];
		for (int idx = 0; idx<N; idx++) scanf("%d", &prices[idx]);
		
		int dp[N_MAX][3][2];
		dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = 0;
		dp[0][0][1] = dp[0][1][1] = dp[0][2][1] = -1;
		for (int idx = 1; idx < N; idx++) {
			dp[idx][0][0] = 0;
			dp[idx][0][1] = -1;
		}
		for (int idx = 1;idx<=N; idx++){
			for (int p = 1; p <= 2; p++){
				if (dp[idx - 1][p][1] == -1) dp[idx][p][0] = dp[idx - 1][p][0];
				else dp[idx][p][0] = max(dp[idx - 1][p][0], dp[idx - 1][p][1] + prices[idx - 1]);
				if (dp[idx - 1][p][1] == -1) dp[idx][p][1] = dp[idx - 1][p - 1][0] - prices[idx - 1];
				else dp[idx][p][1] = max(dp[idx - 1][p][1], dp[idx - 1][p - 1][0] - prices[idx - 1]);
			}
		}

		int answer = dp[N][2][0];
		printf("%d\n", answer);
	}
	return 0;
}
