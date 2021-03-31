/*
Google Code Jam, Qualification Round 2016, Problem B. Revenge of the Pancakes
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard#s=p1
Finished, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

char str[101];
int N;

int main() {

	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%s\n", str);
		N = strlen(str);
		int cnt = 0;
		for (int i = 1; i <= N - 1; i++) {
			if (str[i] != str[i - 1]) cnt++;
		}
		
		if (str[N - 1] == '-') cnt++;
		printf("Case #%d: %d\n", ii, cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}