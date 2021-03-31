/*
Google Code Jam, Qualification Round 2016, Problem C. Coin Jam
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard#s=p2
By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stack>
using namespace std;

bool Prime[65536];
long long factor[11];
bool isPrime(long long d) {
	if (d < 65536 && !Prime[d]) return false;
	int bnd = sqrt(d);
	for (int i = 2; i <= bnd; i++) {
		if (d%i == 0) {
			if (d < 65536) Prime[d] = false;
			return false;
		}
	}
	return true;
}

long long translate(long long d, int h) {
	long long  ans = 0;
	int tmp = 0;
	stack<int> s;
	while (!s.empty()) s.pop();
	while (d>0) {
		tmp = d % 10;
		s.push(tmp);
		d /= 10;
	}
	while (!s.empty()) {
		ans = ans*h + s.top();
		s.pop();
	}
	return ans;
}

long long create(int d) {
	long long ans=1;
	d--;
	while (d--) ans *= 10;
	return ++ans;
}

bool check(long long d) {
	bool flag = true;
	long long tmp;
	for (int i = 2; i <= 10; i++) {
		tmp = translate(d, i);
		bool bb = isPrime(tmp);
		if (bb) {
			flag = false;
			break;
		}
		for (long long j = 2; j <= tmp / 2; j++) {
			if (tmp%j == 0) {
				factor[i] = j;
				break;
			}
		}
	}
	return flag;
}

long long update(long long d, int N) {
	int pos = 1;
	for (; d % 10 == 1; pos++) d /= 10;
	d++;
	for (; pos > 1; pos--) d *= 10;
	if(d%10==0) d++;
	return d;
}

int main() {

	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	for (int iii = 0; iii < 65536; iii++) Prime[iii] = true;
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		int N, J;
		scanf("%d %d", &N, &J);
		long long ans = create(N);
		printf("Case #%d:\n", ii);
		int i;
		for (i = 0; i < J; ans=update(ans, N)) {
			if (!check(ans)) 
				continue;
			printf("%lld", ans);
			for (int j = 2; j <= 10; j++) printf(" %lld", factor[j]);
			printf("\n");
			i++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}