#include <iostream>
#include <cmath>
#define MAZE_SIZE 8
#define N_MAX 16
using namespace std;

int data[MAZE_SIZE+1][MAZE_SIZE+1];
int sum[MAZE_SIZE+1][MAZE_SIZE+1];
double dp[N_MAX+1][MAZE_SIZE+1][MAZE_SIZE+1][MAZE_SIZE+1][MAZE_SIZE+1];

double getLocalSumSquare(int x1, int y1, int x2, int y2){
	double ans = (double)(sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
	return ans*ans;
}

double min(double a, double b) { return (a < b) ? a : b; }

int main(){
	int N;
	while (scanf("%d", &N) != EOF){
		int total = 0;
		for (int i = 1; i <= MAZE_SIZE;i++)
		for (int j = 1; j <= MAZE_SIZE; j++){
			scanf("%d", &data[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + data[i][j];
			total += data[i][j];
		}
		for (int x1 = 1; x1 <= MAZE_SIZE;x1++)
		for (int y1 = 1; y1 <= MAZE_SIZE;y1++)
		for (int x2 = x1; x2 <= MAZE_SIZE;x2++)
		for (int y2 = y1; y2 <= MAZE_SIZE; y2++)
			dp[0][x1][y1][x2][y2] = getLocalSumSquare(x1, y1, x2, y2);
		for (int k = 1; k < N;k++)
		for (int x1 = 1; x1 <= MAZE_SIZE;x1++)
		for (int y1 = 1; y1 <= MAZE_SIZE;y1++)
		for (int x2 = x1; x2 <= MAZE_SIZE;x2++)
		for (int y2 = y1; y2 <= MAZE_SIZE; y2++){
			int t;
			dp[k][x1][y1][x2][y2] = (double)(1 << 30);
			for (t = x1; t < x2; t++){
				dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2],
					dp[0][x1][y1][t][y2] + dp[k - 1][t + 1][y1][x2][y2]);
				dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2],
					dp[k - 1][x1][y1][t][y2] + dp[0][t + 1][y1][x2][y2]);
			}
			for (t = y1; t < y2; t++){
				dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2],
					dp[0][x1][y1][x2][t] + dp[k - 1][x1][t + 1][x2][y2]);
				dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2],
					dp[k - 1][x1][y1][x2][t] + dp[0][x1][t + 1][x2][y2]);
			}
		}
		printf("%.3f\n", 
			sqrt(double(dp[N - 1][1][1][MAZE_SIZE][MAZE_SIZE]) / N 
			- double(sum[MAZE_SIZE][MAZE_SIZE] * sum[MAZE_SIZE][MAZE_SIZE]) / N / N));
	}
	return 0;
}
