/*
挑战编程 程序设计竞赛训练手册，8.4 八皇后问题
回溯法
Finished, By Gao Shuqi, on 2018-04-02
*/

#include <stdio.h>
#include <string.h>
#define N_MAX 100
using namespace std;
int N; /*N<=M_MAX*/
long long cnt;
bool col[N_MAX+1], diag45[2*N_MAX], diag135[2*N_MAX+1];

void visit(int d) {
		for (int j = 1; j <= N; j++) {
			if (col[j]) continue;
			if (diag45[j-d+N]) continue;
			if (diag135[d+j-1]) continue;
			col[j] = true;
			diag45[j - d + N] = true;
			diag135[d + j - 1] = true;
			if (d == N) cnt++;
			else visit(d+1);
			col[j] = false;
			diag45[j - d + N] = false;
			diag135[d + j - 1] = false;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		memset(col, 0, sizeof(col));
		memset(diag45, 0, sizeof(diag45));
		memset(diag135, 0, sizeof(diag135));
		scanf("%d", &N);
		cnt = 0;
		visit(1);
		printf("Case #%d: %lld\n", ii, cnt);
	}
	return 0;
}