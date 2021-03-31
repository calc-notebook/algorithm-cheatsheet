/*
Google Code Jam, Practice Section 2018, Problem B. Senate Evacuation
Retrieved from https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/00000000000004c0
 Finished, By Gao Shuqi, on 2018-03-31.
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int N;
struct Party{
	string name;
	int cnt;
}party[26];
stack<string> ans;

bool cmp(Party a, Party b) { return (a.cnt > b.cnt) ? true : false; }

int find(string s, int d) {
	int poc = 0;
	for (; poc <= d && s != party[poc].name; poc++);
	return poc;
}

bool cal(int t, int n) {
	sort(party, party + n, cmp);
	for (; party[n - 1].cnt == 0; n--);
	if (t == 2 && n == 2) {
		ans.push(party[0].name + party[1].name);
		return true;
	}
	else if (t == 2) return false;
	else if (n>=2 && 2 * party[1].cnt <= t - 2 && party[0].cnt>=2) {
		string str_tmp = party[0].name;
		party[0].cnt -= 2;
		bool tmp_bool = cal(t - 2, n);
		if (tmp_bool) { ans.push(str_tmp + str_tmp); return true; }
		party[find(str_tmp, n)].cnt += 2;
		return false;
	}
	else if (n>=2 && 2 * party[1].cnt <= t - 1) {
		string str_tmp = party[0].name;
		party[0].cnt --;
		bool tmp_bool = cal(t - 1, n);
		if (tmp_bool) { ans.push(str_tmp); return true; }
		party[find(str_tmp, n)].cnt ++;
		return false;
	}
	else if ((n > 2 && 2 * party[2].cnt <= t - 2) || n==2) {
		string str_tmp1 = party[0].name;
		string str_tmp2 = party[1].name;
		party[0].cnt--;
		party[1].cnt--;
		bool tmp_bool = cal(t - 2, n);
		if (tmp_bool) { ans.push(str_tmp1 + str_tmp2); return true; }
		party[find(str_tmp1, n)].cnt++;
		party[find(str_tmp2, n)].cnt++;
		return false;
	}
	else
		return false;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		int total = 0, tmp;
		for (int i = 0; i < N; i++) { party[i].name = 'A' + i; scanf("%d", &tmp); party[i].cnt = tmp; total += tmp; }
		while (!ans.empty()) ans.pop();
		cal(total, N);
		cout<<"Case #"<<ii<<":";
		while (!ans.empty()) {
			cout << " ";
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}
	return 0;
}