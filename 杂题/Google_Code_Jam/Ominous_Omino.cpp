/*
Google Code Jam, Qualification Round 2015, Problem D. Ominous Omino
Retrieved from https://code.google.com/codejam/contest/6224486/dashboard#s=p3
Finished, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int Max(int a, int b) { return (a > b) ? a : b; }
int Min(int a, int b) { return (a < b) ? a : b; }

int main() {

	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		int X, R, C,S,L;
		scanf("%d%d%d", &X, &R, &C);
		S = Min(C, R);
		L = Max(C, R);
		bool ans;
		if ((S*L) % X != 0) ans = true;
		else if (X == 3 && S == 1) ans = true;
		else if (X == 4 && S <= 2) ans = true;
		else if (X == 5 && (S <= 2 || (S == 3 && L == 5))) ans = true;
		else if (X == 6 && S <= 3) ans = true;
		else if (X >= 7) ans = true;
		else ans = false;
		if (!ans)
			printf("Case #%d: GABRIEL\n", ii);
		else
			printf("Case #%d: RICHARD\n", ii);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}