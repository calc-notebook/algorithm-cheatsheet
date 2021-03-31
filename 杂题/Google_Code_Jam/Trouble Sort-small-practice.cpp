/*
Google Code Jam, Round 1A 2018, Problem B. Trouble Sort
Retrieved from https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
排序
Completed, By Gao Shuqi, on 2018-04-16.
*/
#include <iostream>
#include <algorithm>
#define N_MAX 100
using namespace std;

int N, data[N_MAX], data_st[N_MAX];

void sort3() {
	bool done = false;
	while (!done) {
		done = true;
		for (int i = 0; i < N - 2; i++) {
			if (data[i]>data[i + 2]) {
				done = false;
				int tmp;
				tmp = data[i];
				data[i] = data[i + 2];
				data[i + 2] = tmp;
			}
		}
	}
}

bool cmp(int a, int b) { return (a < b) ? true : false; }

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &data[i]);
			data_st[i] = data[i];
		}
		sort3();
		sort(data_st, data_st+N, cmp);
		int poc;
		for (poc = 0; poc < N; poc++) {
			if (data[poc] != data_st[poc]) break;
		}
		if (poc == N) printf("Case #%d: OK\n", ii);
		else printf("Case #%d: %d\n", ii, poc);
	}
	return 0;
}

