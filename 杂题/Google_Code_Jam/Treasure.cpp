/*
 Google Code Jam, Qualification Round 2013, Problem D. Treasure
 Retrieved from https://code.google.com/codejam/contest/2270488/dashboard#s=p3
 Finished, By Gao Shuqi, on 2018-03-28.
 */

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct Chest{
	int T;
	int total;
	int k[401];
}chest[201];
int key[201];
bool opened[201];
int K, N;
stack<int> order;

bool finished() {
	for (int i = 1; i <= N; i++) {
		if (!opened[i]) return false;
	}
	return true;
}

bool openChest(int d) {
	key[chest[d].T]--;
	opened[d] = true;
	for (int i = 1; i <= chest[d].total; i++) {
		key[chest[d].k[i]]++;
	}
	if (finished()) { order.push(d); return true; }
	for (int i = 1; i <= N; i++) {
		if (opened[i]) continue;
		if (key[chest[i].T] == 0) continue;
		bool tmp=openChest(i);
		if (tmp) { order.push(d); return true; }
	}
	key[chest[d].T]++;
	opened[d] = false;
	return false;
}

int main() {
	freopen("D-small-practice.in", "r", stdin);
	freopen("D-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &K, &N);
		memset(key, 0, sizeof(key));
		memset(opened, 0, sizeof(opened));
		while (!order.empty()) order.pop();
		for (int i = 1; i <= K; i++) {
			int tmp;
			scanf("%d", &tmp);
			key[tmp]++;
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d%d", &chest[i].T, &chest[i].total);
			for (int j = 1; j <= chest[i].total; j++) scanf("%d", &chest[i].k[j]);
		}
		bool flag=false;
		for (int i = 1; i <= N; i++) {
			if (opened[i]) continue;
			if (key[chest[i].T] == 0) continue;
			flag = openChest(i);
			if (flag) break;
		}
		if (!flag) printf("Case #%d: IMPOSSIBLE\n", ii);
		else{
			printf("Case #%d:", ii);
			while (!order.empty()) { printf(" %d", order.top()); order.pop(); }
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}