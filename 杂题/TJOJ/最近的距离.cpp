/*
Tongji OJ, Problem 1084. 最近的距离
Retrieved from http://acm.tongji.edu.cn/contest.php?cid=1084
二项式求极值
Completed, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <math.h>
using namespace std;

double x1, y01, dx1, dy1, x2, y2, dx2, dy2;
double ans;

int main() {
	cin >> x1 >> y01 >> dx1 >> dy1 >> x2 >> y2 >> dx2 >> dy2;
	double A = pow(dx1 - dx2, 2) + pow(dy1 - dy2, 2);
	double B = 2 * (dx1-dx2)*(x1-x2)+2*(dy1-dy2)*(y01-y2);
	double C = pow(x1 - x2, 2) + pow(y01 - y2, 2);
	if (A == 0) ans = C;
	else {
		double loc = -B / (2 * A);
		double minium = C - B*B / (4 * A);
		if (loc <= 0) ans = C;
		else ans = minium;
	}
	ans = sqrt(ans);
	printf("%.9f", ans);
	return 0;
}
