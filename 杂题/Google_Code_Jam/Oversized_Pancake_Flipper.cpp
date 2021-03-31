/*
Google Code Jam , Qualification Round 2017, Problem A. Oversized Pancake Flipper
Retrieved from https://code.google.com/codejam/contest/3264486/dashboard
Finished, By Gao Shuqi, on 2018-03-18.
*/
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

char s[1001];
int k;
string str;

void flip(int d) {
	for (int i = d; i < d + k; i++) {
		if (str[i] == '+')
			str[i] = '-';
		else
			str[i] = '+';
	}
}

int main() {

	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);

	int T; // the number of tests, 1<=T<=100
	scanf("%d", &T);
	for(int i=1;i<=T;i++) {
		scanf("%s%d", s, &k);
		str = s;
		int length = str.size() - k;
		int pos = str.find('-', 0);
		int counter = 0;
		while (pos != string::npos && pos<=length) {
			flip(pos);
			counter++;
			pos = str.find('-', pos);
		}
		if (pos == string::npos)
			printf("Case #%d: %d\n", i, counter);
		else
			printf("Case #%d: IMPOSSIBLE\n", i);
	}

	fclose(stdin);
	fclose(stdout);
	//getchar();
	//getchar();
	return 0;
}