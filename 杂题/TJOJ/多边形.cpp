/*
Tongji OJ, Problem 1004. 多边形
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1004
计算几何
Completed, By Gao Shuqi, on 2018-04-10
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#define N_MAX 1000
#define EPSILON 1e-10
using namespace std;

struct point{
	int x, y;
	double angle;
	double r;
}dot[N_MAX];
int N ,polygon[N_MAX], V;

bool cmp1(point a, point b) {
	if (a.x < b.x || (a.x == b.x && a.y < b.y)) return true;
	else return false;
}

bool cmp2(point a, point b) {
	return a.angle < b.angle;
}

bool cmp3(point a, point b) {
	return a.r < b.r;
}

bool cmp4(point a, point b) {
	return a.r > b.r;
}

double signed_triangle_area(point a, point b, point c) {
	return ((a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - c.x*b.y) / 2.0);
}

bool ccw(point a, point b, point c) {
	return (signed_triangle_area(a, b, c) > EPSILON);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d%d", &dot[i].x, &dot[i].y);
		sort(dot, dot + N, cmp1);
		dot[0].angle = -1;
		for (int i = 1; i < N; i++) {
			double tmp = (dot[i].y - dot[0].y) / (sqrt((dot[i].x - dot[0].x)*(dot[i].x - dot[0].x) + (dot[i].y - dot[0].y)*(dot[i].y - dot[0].y)));
			dot[i].angle = -tmp;
		}
		sort(dot + 1, dot + N, cmp2);
		V == 0;
		polygon[V++] = 0;
		polygon[V++] = 1;
		for (int i = 2; i < N; i++) {
			bool convex = ccw(dot[polygon[V - 2]], dot[polygon[V - 1]], dot[i]);
			if (convex) polygon[V - 1] = i;
			else polygon[V++] = i;
		}

		//处理顶点共线退化问题
		int poc = 2;
		for (; poc < N; poc++) {
			double tmp = signed_triangle_area(dot[0], dot[1], dot[poc]);
			if (tmp>EPSILON || tmp < -EPSILON) break;
		}
		if (poc>2) {
			poc--;
			for (int i = 1; i <= poc; i++) {
				double tmp = (dot[i].x - dot[0].x)*(dot[i].x - dot[0].x) + (dot[i].y - dot[0].y)*(dot[i].y - dot[0].y);
				dot[i].r = tmp;
			}
			sort(dot + 1, dot + poc + 1,cmp3);
		}
		poc = N-2;
		for (; poc >=0; poc--) {
			double tmp = signed_triangle_area(dot[0], dot[N-1], dot[poc]);
			if (tmp>EPSILON || tmp < -EPSILON) break;
		}
		if (poc<N-2) {
			poc++;
			for (int i = N-1; i >= poc; i--) {
				double tmp = (dot[i].x - dot[0].x)*(dot[i].x - dot[0].x) + (dot[i].y - dot[0].y)*(dot[i].y - dot[0].y);
				dot[i].r = tmp;
			}
			sort(dot + poc, dot + N, cmp4);
		}
		
		bool danger = true, stable = true;;
		for (int i = 0; i < N-1; i++) {
			double tmp = signed_triangle_area(dot[i], dot[i+1], dot[(i+2)%N]);
			if (tmp>EPSILON || tmp < -EPSILON) {
				if (danger) { stable = false; break; }
				else{ danger = true; continue; }
			}
			else {
				danger = false;
				continue;
			}
		}
		if (stable) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}