/*
Google Code Jam, Round 1A 2018, Problem B. Trouble Sort
Retrieved from https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
≈≈–Ú
Completed, By Gao Shuqi, on 2018-04-16.
*/

#include <iostream>
#include <algorithm>
#define N_MAX 102
using namespace std;

int N, data[N_MAX], data_st[N_MAX];

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &data[i]);
		}
		int sub1[N_MAX], sub2[N_MAX];
		for (int i = 0; i < N; i += 2) { sub1[i / 2] = data[i]; sub2[(i + 1) / 2] = data[i + 1]; }
		sort(sub1, sub1 + (N + 1) / 2);
		sort(sub2, sub2 + N / 2);
		bool answer = true;
		int poc = 0;
		for (int i = 0; i < N / 2; i++) {
			if (sub1[i]>sub2[i]) { poc = 2 * i + 1; answer = false; break; }
		}
		if (N % 2 == 1 && sub1[N / 2]<sub2[N / 2 - 1]) { poc = N-2; answer = false; }
		if (answer) printf("Case #%d: OK\n", ii);
		else printf("Case #%d: %d\n", ii, poc);
	}
	return 0;
}

