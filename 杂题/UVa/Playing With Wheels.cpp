/*
State Space Searching, Easy.
Completed, By Gao Shuqi, on 2018-04-03

Lessons to learn:
The searched state are supposed to be tagged, if not the duplicated searching will be rather time-consuming.
搜索过的状态需要打上标记，否则重复搜索可能带来巨大的时间开销.
*/
#include <stdio.h>
#include <queue>
using namespace std;

struct State{
	int a[4];
	int cnt;
};
queue<State> q;
State angel;
int n;
bool visited[10][10][10][10];

bool isAngel(State s) {
	if (s.a[1]==angel.a[1] && s.a[2]==angel.a[2] && s.a[3]==angel.a[3] && s.a[0]==angel.a[0]) return true;
	else return false;
}


int main() {
	int N;
	scanf("%d", &N);
	for (int ii = 0; ii < N; ii++) {
		memset(visited, 0, sizeof(visited));
		State tmp;
		scanf("%d%d%d%d", &tmp.a[0], &tmp.a[1], &tmp.a[2], &tmp.a[3]);
		tmp.cnt = 0;
		while (!q.empty()) q.pop();
		q.push(tmp);
		visited[tmp.a[0]][ tmp.a[1]][ tmp.a[2]][ tmp.a[3]] = true;
		scanf("%d%d%d%d", &angel.a[0],&angel.a[1],&angel.a[2], &angel.a[3]);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) { int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); visited[a][b][c][d] = true; }
		bool flag=false;
		int cnt=0;
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			//printf("%d-%d-%d-%d\n", tmp.a[0], tmp.a[1], tmp.a[2], tmp.a[3]);
			if (isAngel(tmp)) { flag = true; cnt = tmp.cnt; break; }
			for (int i = 0; i < 4; i++) {
				State tmp1 = tmp;
				tmp1.a[i] = (tmp.a[i] + 1) % 10;
				tmp1.cnt++;
				if (visited[tmp1.a[0]][tmp1.a[1]][tmp1.a[2]][tmp1.a[3]]) continue;
				q.push(tmp1);
				visited[tmp1.a[0]][tmp1.a[1]][tmp1.a[2]][tmp1.a[3]] = true;
			}
			for (int i = 0; i < 4; i++) {
				State tmp1 = tmp;
				tmp1.a[i]=((tmp.a[i]-1)+10)%10;
				tmp1.cnt++;
				if (visited[tmp1.a[0]][tmp1.a[1]][tmp1.a[2]][tmp1.a[3]]) continue;
				q.push(tmp1);
				visited[tmp1.a[0]][tmp1.a[1]][tmp1.a[2]][tmp1.a[3]] = true;
			}
		}
		if (flag) printf("%d\n", cnt);
		else printf("-1\n");
	}
	return 0;
}
