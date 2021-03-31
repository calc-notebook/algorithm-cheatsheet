#include <iostream>
#include <algorithm>
#include <cmath>
#define N_MAX 200000
using namespace std;

long long calInversions(int* data, int length){
	if (length == 1) return 0;
	long long cnt_left = calInversions(data, length / 2);
	long long cnt_right = calInversions(data + length / 2, length - length / 2);
	long long cnt_mixture = 0;
	int idx1 = 0, idx2 = length / 2;
	while (idx1 < length / 2 && idx2 < length){
		if (data[idx1] <= 2 * data[idx2]) {
			idx1++;
		}
		else{
			cnt_mixture += (length / 2 - idx1);
			idx2++;
		}
	}
	inplace_merge(data, data + length / 2, data + length);
	return cnt_left + cnt_right + cnt_mixture;
}

int main(){
	int N;
	while (scanf("%d", &N) != EOF && N != 0){
		int data[N_MAX];
		for (int idx = 0; idx < N; idx++) scanf("%d", &data[idx]);
		long long answer = calInversions(data, N);
		printf("%lld\n", answer);
	}
	return 0;
}
