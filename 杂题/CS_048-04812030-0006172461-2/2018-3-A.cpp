//
// Created by Sukie on 11/18/2018.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#define N_MAX 100001

using namespace std;

class Point2d{
public:
	int x;
	int y;
};

bool compare_X(Point2d a, Point2d b){
	return a.x < b.x;
}

bool compare_Y(Point2d a, Point2d b){
	return a.y < b.y;
}

double getDistance(Point2d a, Point2d b){
	return sqrt(((double)a.x - (double)b.x)*((double)a.x - (double)b.x)
		      + ((double)a.y - (double)b.y)*((double)a.y - (double)b.y));
}

Point2d points[N_MAX];


double closest_pair(Point2d* data, int length){
	if (length == 1) return 1e11;

	double L = (data[length / 2 - 1].x + data[length/2].x)/2.0;
	double sigma1 = closest_pair(data, length / 2);
	double sigma2 = closest_pair(data + length / 2, length - length / 2);
	double sigma=(sigma1<sigma2)?sigma1:sigma2;

	inplace_merge(data, data + length / 2, data + length, compare_Y);
	Point2d localpoints[N_MAX];
	int cnt_local = 0;
	for (int idx = 0; idx < length; idx++){
		if (abs(data[idx].x - L) >= sigma) continue;
		localpoints[cnt_local++] = data[idx];
	}
	for (int idx = 0; idx < cnt_local; idx++){
		//if (abs(data[idx].x - L) >= sigma) continue;
		for (int p = idx + 1; p < idx + 12 && p < cnt_local; p++){
			double temp_dist = getDistance(localpoints[idx], localpoints[p]);
			if (temp_dist < sigma) sigma = temp_dist;
		}
	}
	return sigma;

}


int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		for (int idx = 0; idx<N; idx++) scanf("%d%d", &points[idx].x, &points[idx].y);
		sort(points, points + N, compare_X);
		double answer = closest_pair(points, N);
		printf("%.6f\n", answer);
	}
	return 0;
}
