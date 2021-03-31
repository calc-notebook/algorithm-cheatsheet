#include <iostream>
using namespace std;

const int N_MAX = 100000 + 1;
const int MAX_INT = -1e11;
int N;
int p[N_MAX];
int dp[N_MAX][3][2];

int max(int a, int b) { return (a > b) ? a : b; }
int stock_exchange(){
	// TO DO: init dp[]
	for (int i = 0; i <= N; i++) dp[i][0][0] = 0;
	for (int i = 0; i <= 2; i++) dp[0][i][0] = 0;
	for (int i = 0; i <= N; i++) dp[i][0][1] = -1;
	for (int i = 0; i <= 2; i++) dp[0][i][1] = -1;

	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= 2; j++){
		if (dp[i - 1][j][1] == -1) dp[i][j][0] = dp[i - 1][j][0];
		else dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + p[i]);
		if (dp[i - 1][j][1] == -1) dp[i][j][1] = dp[i - 1][j - 1][0] - p[i];
		else dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - p[i]);
	}
	return dp[N][2][0];
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
		int answer = stock_exchange();
		printf("%d\n", answer);
	}
	return 0;
}