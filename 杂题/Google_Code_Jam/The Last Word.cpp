/*
Google Code Jam, Round 1A 2016. Problem A. The Last Word
Retrieved from https://code.google.com/codejam/contest/4304486/dashboard
双端队列
Completed, By Gao Shuqi, on 2018-04-18.
*/
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#define N_MAX 1000
using namespace std;

char str[N_MAX];
char ans[N_MAX];
queue<char> q;
stack<char> s;

int main() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%s", str);
		while (!q.empty()) q.pop();
		while (!s.empty()) s.pop();
		int N = strlen(str);
		s.push(str[0]);
		for (int i = 1; i < N; i++) {
			if (str[i] >= s.top()) s.push(str[i]);
			else q.push(str[i]);
		}
		int poc = 0;
		while (!s.empty()) { ans[poc++] = s.top(); s.pop(); }
		while (!q.empty()) { ans[poc++] = q.front(); q.pop(); }
		printf("Case #%d: ", ii);
		for (int i = 0; i < N; i++) printf("%c", ans[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}