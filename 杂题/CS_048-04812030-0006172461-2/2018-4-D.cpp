#include <iostream>
#include <cstring>
#define N_MAX 101
using namespace std;

int max(int a, int b){ return (a > b) ? a : b; }

int process(int* data, int length){
	int dp[N_MAX][N_MAX] = { 0 };
	for (int idx = 1; idx <= length; idx++) dp[idx][idx + 1] = 0;
	for (int idx = 1; idx <= length - 2; idx++) dp[idx][idx + 2] = data[idx] * data[idx+1] * data[idx + 2];
	for (int idx1 = 3; idx1 <= length - 1;idx1++)
	for (int idx2 = 1; idx2 <= length - idx1; idx2++){
		dp[idx2][idx2 + idx1] = 1e10;
		for (int p = idx2 + 1; p <= idx1 + idx2 - 1; p++){
			if (dp[idx2][idx2 + idx1] > dp[idx2][p] + dp[p][idx1 + idx2] + data[idx2] * data[p] * data[idx1 + idx2])
				dp[idx2][idx2 + idx1] = dp[idx2][p] + dp[p][idx1 + idx2] + data[idx2] * data[p] * data[idx1 + idx2];
		}
	}
	return dp[1][length];
}

int main(){
	int N;
	while (scanf("%d", &N) != EOF){
		int data[N_MAX];
		for (int idx = 1; idx <= N; idx++) scanf("%d", &data[idx]);
		int answer = process(data, N);
		printf("%d\n", answer);
	}
	return 0;
}