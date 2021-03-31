/*
Google Code Jam, Qualification Round 2012, Problem A. Speaking in Tongues
Retrieved from https://code.google.com/codejam/contest/1460488/dashboard
Finished, By Gao Shuqi, on 2018-03-28.
*/

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main() {
	freopen("A-small-practice.in", "r", stdin);
	freopen("A-small-practice.out", "w", stdout);
	int T;
	map<char, char> m;
	scanf("%d", &T);
	getchar();
	m.clear();
	m['y'] = 'a'; m['n'] = 'b'; m['f'] = 'c'; m['i'] = 'd'; m['c'] = 'e'; m['w'] = 'f'; m['l'] = 'g'; m['b'] = 'h'; m['k'] = 'i'; m['u'] = 'j'; m['j'] = 'u'; m['g'] = 'v';
	m['o'] = 'k'; m['m'] = 'l'; m['x'] = 'm'; m['s'] = 'n'; m['e'] = 'o'; m['v'] = 'p'; m['z'] = 'q'; m['p'] = 'r'; m['d'] = 's'; m['r'] = 't'; m['t'] = 'w'; m['h'] = 'x';
	m['a'] = 'y'; m['q'] = 'z';
	for (int ii = 1; ii <= T; ii++) {
		char str[101];
		gets(str);
		int n = strlen(str);
		for (int i = 0; i < n; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') str[i] = m[str[i]];
		}
		printf("Case #%d: ", ii);
		for (int i = 0; i < n; i++) printf("%c", str[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}