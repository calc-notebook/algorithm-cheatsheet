#include <iostream>
#define N_MAX 500
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

/*
此问题可以转换为最长公共字符串问题求解
*/
int calculate(char* data1, char* data2, int length){
	short dp[N_MAX + 1][N_MAX + 1];
	for (int idx = 0; idx <= length; idx++) dp[0][idx] = dp[idx][0] = 0;
	for (int idx1 = 1; idx1 <= length;idx1++)
	for (int idx2 = 1; idx2 <= length; idx2++){
		if (data1[idx1 - 1] == data2[idx2 - 1]) dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
		else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
	}
	return length-dp[length][length];
}

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	char data1[N_MAX], data2[N_MAX];
	for (int idx = 0; idx < N; idx++) { scanf("%c", &data1[idx]); data2[N - idx - 1] = data1[idx]; }
	int answer = calculate(data1,data2, N);
	printf("%d\n", answer);
	getchar();
	getchar();
	return 0;
}
