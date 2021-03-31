#include <iostream>
#define N_MAX 50001
#define MINIMUM -1e10
using namespace std;

int Max(int a, int b) { return (a > b) ? a : b; }

int process(int* data, int length){
	int sum = 0;
	int max = MINIMUM;
	int left[N_MAX];
	for (int idx = 0; idx < length; idx++){
		sum = Max(sum + data[idx], data[idx]);
		max = Max(sum, max);
		left[idx] = max;
	}
	sum = 0;
	max = MINIMUM;
	int result = max;
	for (int idx = length - 1; idx >= 0; idx--){
		if (idx < length - 1) result = Max(result, left[idx] + max);
		sum = Max(sum + data[idx], data[idx]);
		max = Max(sum, max);
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		int data[N_MAX];
		for (int idx = 0; idx < N; idx++) scanf("%d", &data[idx]);
		int answer = process(data, N);
		printf("%d\n", answer);
	}
	return 0;
}