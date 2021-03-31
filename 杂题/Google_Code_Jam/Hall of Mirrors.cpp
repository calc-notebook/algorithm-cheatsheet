/*
Google Code Jam, Qualification Round 2012, Problem D. Hall of Mirrors
Retrieved from https://code.google.com/codejam/contest/1460488/dashboard#s=p3
Finished, By Gao Shuqi, on 2018-04-01.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Shadow{
	double x, y;
	int type; 
};
char map[31][31];
int H, W, D;
double X, Y;
queue<Shadow> q;

bool visible(Shadow s) {
	double tmp = (s.x - X)*(s.x - X) + (s.y - Y)* (s.y - Y);
	return tmp <= D*D;
}

bool Next(double x, double y, double &next_x, double &next_y, int type) {
	if (type == 1 && y>1) { next_x = x; next_y = 2 - y; return true; }
	else if (type == 2 && x<W-1) { next_x = 2 * W-2 - x; next_y = y; return true; }
	else if (type == 3 && y<H-1) { next_x = x; next_y = 2 * H -2- y; return true; }
	else if (type == 4 && x>1) { next_x = 2 - x; next_y = y; return true; }
	else
		return false;
}

bool isBlocked(Shadow a, Shadow b) {
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int cnt = 0;
		scanf("%d%d%d", &H, &W, &D);
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin>>map[i][j];
				if (map[i][j] == 'X') { X = i - 0.5; Y = j - 0.5; }
			}
		}
		while (!q.empty()) q.pop();

		Shadow tmp;
		for (int i = 1; i <= 4; i++) {
			double next_x, next_y;
			bool flag = Next(X, Y, next_x, next_y, i);
			if (!flag) continue;
			Shadow tmp;
			tmp.x = next_x;
			tmp.y = next_y;
			tmp.type = i;
			if (visible(tmp)) q.push(tmp);
		}

		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			cnt++;
			for (int i = 1; i <= 4; i++) {
				if (tmp.type == i) continue;
				double next_x, next_y;
				bool flag=Next(tmp.x, tmp.y, next_x, next_y, i);
				if (!flag) continue;
				Shadow tmp1;
				tmp1.x = next_x;
				tmp1.y = next_y;
				tmp1.type = i;
				if (visible(tmp1)) q.push(tmp1);
			}
		}
		printf("Case #%d: %d\n", ii, cnt);
	}
	return 0;
}