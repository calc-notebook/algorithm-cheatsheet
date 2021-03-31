/*
Google Code Jam, Qualification Round 2015, Problem C. Dijkstra
Retrieved from https://code.google.com/codejam/contest/6224486/dashboard#s=p2
By Gao Shuqi, on 2018-03-24.
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int L, X;
string str, instr;

void cal(char a, char b, char &c, char &d) {

}

bool f(int d, char c) {
	bool flag = false;
	if (c == 'k') {
		char ans_value=str[d], ans_sym='+', tmp;
		for (int i = d+1; i < L; i++) {
			cal(ans_value, str[i], ans_value, ans_sym);
		}
		if (ans_value)
	}
	return flag;
}

int main() {

	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d %d", &L, &X);
		cin >> instr;
		str = "";
		for (int i = 1; i <= X; i++) str += instr;
		L *= X;
		bool flag = false;
		for (int i = 0; i < L - 2; i++) {
			if (f(i, 'i')) {
				for (int j = i + 1; j < L - 1; j++) {
					if (f(j, 'j')) {
						for (int k = j + 1; k < L; k++) {
							if (f(k, 'k')) {
								flag=true;
								break;
							}
						}
					}
				}
			}
		}
		if (flag) printf("Case #%d: YES\n");
		else printf("Case #%d: NO\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}