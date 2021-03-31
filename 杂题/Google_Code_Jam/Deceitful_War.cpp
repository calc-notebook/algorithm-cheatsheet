/*
Google Code Jam, Qualification Round 2014, Problem D. Deceitful War
Retrieved from https://code.google.com/codejam/contest/2974486/dashboard#s=p3
By Gao Shuqi, on 2018-03-27.
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N;
double Nao[1001], Ken[1001];
bool destroyed_N[1001], destroyed_K[1001];
bool cmp(double a, double b) { return a > b; }

bool Deceitful() {
	int pos_N, pos_K;
	for (pos_N = 1; destroyed_N[pos_N]; pos_N++);
	for (pos_K = 1; destroyed_K[pos_K]; pos_K++);
	if (Nao[pos_N] > Ken[pos_K]) { destroyed_N[pos_N] = true; destroyed_K[pos_K] = true; return true; }
	else {
		int tail_N;
		for (tail_N = N; destroyed_N[tail_N]; tail_N--);
		destroyed_N[tail_N] = true;
		destroyed_K[pos_K] = true;
		return false;
	}
}

bool War() {
	int pos_N, pos_K;
	for (pos_N = 1; destroyed_N[pos_N]; pos_N++);
	for (pos_K = 1; destroyed_K[pos_K]; pos_K++);
	if (Nao[pos_N] > Ken[pos_K]) { 
		int tail_K;
		for (tail_K = N; destroyed_K[tail_K]; tail_K--);
		destroyed_K[tail_K] = true;
		destroyed_N[pos_N] = true;
		return true; 
	}
	else {destroyed_N[pos_N] = true; destroyed_K[pos_K] = true; return false;}
}

int main() {
	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		memset(Nao, 0, sizeof(Nao));
		memset(Ken, 0, sizeof(Ken));
		for (int i = 1; i <= N; i++) cin>>Nao[i];
		for (int i = 1; i <= N; i++) cin>>Ken[i];
		sort(Nao + 1, Nao + 1 + N, cmp);
		sort(Ken + 1, Ken + 1 + N, cmp);
		int cnt_D = 0;
		memset(destroyed_N, 0, sizeof(destroyed_N));
		memset(destroyed_K, 0, sizeof(destroyed_K));
		for (int k = 0; k < N; k++) {
			bool tmp = Deceitful();
			if (tmp) cnt_D++;
		}
		int cnt_W = 0;
		memset(destroyed_N, 0, sizeof(destroyed_N));
		memset(destroyed_K, 0, sizeof(destroyed_K));
		for (int k = 0; k < N; k++) {
			bool tmp = War();
			if (tmp) cnt_W++;
		}
		printf("Case #%d: %d %d\n", ii, cnt_D, cnt_W);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}