/*
Google Code Jam, Round 1C 2017. Problem C. Core Training
Retrieved from https://code.google.com/codejam/contest/3274486/dashboard#s=p2
最大值问题
Completed, By Gao Shuqi, on 2018-04-18.
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define N_MAX 50
using namespace std;

double P[N_MAX];
bool visited[N_MAX];
double ans1,tmp;

double min(double a, double b) { return (a < b) ? a : b; }

double f(int d,int N, int K) {
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		if (d == 1) tmp = P[i];
		else tmp *= P[i];
		if (K == d) { ans1 *= (1 - tmp); visited[i] = false; tmp /= P[i]; continue; }
		f(d + 1, N, K);
		visited[i] = false;
		tmp /= P[i];
	}
 }

double cal(int N, int K, double U) {
	sort(P, P + N);
	if (K == 1) return min(P[N - 1] + U, 1);
	int poc = N - K;
	double level = P[poc];
	int num = 1;
	while (U>0) {
		if (poc >= N - 1) break;
		if (U >= (P[poc + 1] - level)*num) { U -= ((P[poc + 1] - level)*num); level = P[++poc]; num++; }
		else { level += U / num; U = 0; }
	}
	if (U > 0)  level = min(1, level + U / num); 
	for (int i = N - K; i < N - K + num; i++) P[i] == level;
	if(N == K) {
		double ans = pow(level, num);
		for (int i = N - K + num; i < N; i++) ans *= P[i];
		return ans;
	}
	else{
		memset(visited, 0, sizeof(visited));
		ans1 = 1.0;
		f(1,N,K);
		return 1-ans1;
	}
}
int main() {
	//freopen("C-small-practice-1.in", "r", stdin);
	//freopen("C-small-practice-1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int N, K;
		scanf("%d%d", &N, &K);
		double U;
		cin >> U;
		for (int i = 0; i < N; i++) cin >> P[i];
		double ans;
		ans = cal(N, K, U);
		printf("Case #%d: %.8f\n", ii, ans);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}