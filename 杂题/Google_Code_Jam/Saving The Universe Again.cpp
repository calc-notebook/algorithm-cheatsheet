/*
Google Code Jam, Round 1A 2018, Problem A. Saving The Universe Again
Retrieved from https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
字符串
Completed, By Gao Shuqi, on 2018-04-16.
*/

#include <iostream>
#include <string.h>
#define N_MAX 100
using namespace std;

int D,N;
char str[N_MAX];

int cal() {
	int strength = 1, damage=0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'C') strength *= 2;
		else damage += strength;
	}
	return damage;
}

int find() {
	int poc = N - 1;
	for (; poc >= 1 && !(str[poc]=='S' && str[poc-1]=='C'); poc--);
	return poc;
}

void swap(int poc) {
	str[poc] = 'C';
	str[poc - 1] = 'S';
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%s", &D, str);
		N = strlen(str);
		int damage = cal();
		if (damage <= D) { printf("Case #%d: 0\n", ii); continue; }
		int cnt = 0,poc;
		while (damage > D) {
			poc = find();
			if (poc == 0) { printf("Case #%d: IMPOSSIBLE\n", ii); break; }
			else { swap(poc); damage = cal(); cnt++; }
		}
		if (poc != 0) printf("Case #%d: %d\n", ii, cnt);
	}
	return 0;
}