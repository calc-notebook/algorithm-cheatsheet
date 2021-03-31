/*
Google Code Jam , Qualification Round 2017, Problem A. Standing Ovation
Retrieved from https://code.google.com/codejam/contest/6224486/dashboard
Finished, By Gao Shuqi, on 2018-03-24.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int cnt[1001];
char str[1001];
int preSum[1001];
int S;

int main() {

	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);

	int T; // the number of tests, 1<=T<=100
	scanf("%d", &T);
	for(int ii=1;ii<=T;ii++) {
		memset(cnt, 0, sizeof(cnt));
		memset(preSum, 0, sizeof(preSum));
		scanf("%d %s", &S, str);
		for (int i = 0; i <= S; i++) cnt[i] = str[i] - '0';
		for (int i = 1; i <= S; i++) preSum[i] = preSum[i - 1] + cnt[i - 1];
		int ans = 0;
		for (int i = 1; i <= S; i++) {
			if (i <= preSum[i] || cnt[i]==0) continue;
			int tmp = i - preSum[i];
			ans += tmp;
			cnt[i] += tmp;
			for (int j = i + 1; j <= S; j++) preSum[j] += tmp;
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}