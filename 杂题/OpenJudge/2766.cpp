#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;

const int N_MAX = 100;
int N;
int matrix[N_MAX][N_MAX];
int b[N_MAX];
int dp[N_MAX];

int max(int a, int b) { return (a > b) ? a : b; }

int max_sub_array(){
	memset(dp, 0, sizeof(dp));
	dp[0] = b[0];
	for (int i = 1; i < N; i++){
		if (dp[i - 1]>0) dp[i] = dp[i - 1] + b[i];
		else dp[i] = b[i];
	}
	int answer = INT_MIN;
	for (int i = 0; i < N; i++) answer = max(answer, dp[i]);
	return answer;
}

int max_sub_matrix(){
	int answer = INT_MIN;
	for (int i = 0; i < N; i++){
		memset(b, 0, sizeof(b));
		for (int j = i; j < N; j++){
			for (int c = 0; c < N; c++) b[c] += matrix[j][c];
			answer = max(answer, max_sub_array());
		}
	}
	return answer;
}


int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		scanf("%d", &matrix[i][j]);
	int answer = max_sub_matrix();
	printf("%d\n", answer);
	return 0;
}
/* shuxiaoqin */