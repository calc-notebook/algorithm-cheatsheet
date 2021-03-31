/*
Simulation, Easy
Google Code Jam, Practice Section 2011, Problem B. Magicka
Retrieved from https://code.google.com/codejam/contest/975485/dashboard#s=p1
Completed, By Gao Shuqi, on 2018-04-06.

Lessons to Learn
Using Hash Table to record the correspondence of the combination and opposition.
使用哈希表存储元素的合成和对立关系
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#define N_MAX 100
using namespace std;

int combine[26][26], opposite[26];
int N, poc;
char str[N_MAX], ans[N_MAX];

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		memset(combine, -1, sizeof(combine));
		memset(opposite, -1, sizeof(opposite));
		int tmp;
		char a, b, c;
		scanf("%d", &tmp);
		for (int i = 0; i < tmp; i++) { cin >> a >> b >> c; combine[a - 'A'][b - 'A'] = c - 'A'; combine[b - 'A'][a - 'A'] = c - 'A'; }
		scanf("%d", &tmp);
		for (int i = 0; i < tmp; i++) { cin >> a >> b; opposite[a - 'A'] = b - 'A'; opposite[b - 'A'] = a - 'A'; }
		scanf("%d", &N);
		scanf("%s", str);
		poc = -1;
		for (int i = 0; i < N; i++) {
			if (poc == -1) { ans[++poc] = str[i]; continue; }
			if (combine[ans[poc] - 'A'][str[i] - 'A'] != -1) { ans[poc] = combine[ans[poc] - 'A'][str[i] - 'A'] + 'A'; continue; }
			for (int j = 0; j <= poc; j++) {
				if (opposite[ans[j] - 'A']!=-1 && opposite[ans[j] - 'A'] + 'A' == str[i]) { poc = -1; break; }
			}
			if (poc != -1) ans[++poc] = str[i];
		}
		printf("Case #%d: [", ii);
		if (poc == -1) {printf("]\n"); continue;}
		for (int i = 0; i < poc; i++) {
			printf("%c, ", ans[i]);
		}
		printf("%c]\n",ans[poc]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

