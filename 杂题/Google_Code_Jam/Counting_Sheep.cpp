/*
Google Code Jam, Qualification Round 2016, Problem A. Counting Sheep
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard
Finished, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

bool digit[10];
bool finished;

void setDigit(int d) {
	while (d > 0) {
		int tmp = d % 10;
		digit[tmp] = true;
		d /= 10;
	}
}

int main() {

	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i <= 9; i++) digit[i] = false;
		finished = false;
		if (N == 0) {
			printf("Case #%d: INSOMNIA\n", ii);
			continue;
		}
		int p;
		for(p=1;!finished;p++) {
			setDigit(N*p);
			finished = true;
			for (int j = 0; j <= 9; j++) {
				if (!digit[j]) {
					finished = false;
					break;
				}
			}
		}
		p--;
		printf("Case #%d: %d\n", ii, p*N);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}