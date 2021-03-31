#include <iostream>
#define N_MAX 110
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

/* dp-version */
int calculate_dp1(int *data, int length){
	int dp_left[N_MAX], dp_right[N_MAX];
	dp_left[0] = 1;
	dp_right[length - 1] = 1;
	for (int idx = 1; idx < length; idx++){
		if (data[idx]>data[idx - 1]) dp_left[idx] = dp_left[idx - 1] + 1;
		else dp_left[idx] = 1;
		if (data[length - 1 - idx] > data[length - idx]) dp_right[length - 1 - idx] = dp_right[length - idx] + 1;
		else dp_right[length - idx - 1] = 1;
	}
	int answer = 0;
	for (int idx = 0; idx < length; idx++) answer = max(max(answer, dp_left[idx]), dp_right[idx]);
	return answer;
}

int calculate_dp2(int *data, int length){
	int dp_left[N_MAX], dp_right[N_MAX];
	dp_left[0] = 1;
	dp_right[length - 1] = 1;
	for (int idx = 1; idx < length; idx++){
		dp_left[idx] = 1;
		for (int p = 0; p < idx; p++){
			if (data[idx]>data[p]) dp_left[idx] = max(dp_left[idx], dp_left[p] + 1);
		}
	}
	for (int idx = length-2; idx >=0; idx--){
		dp_right[idx] = 1;
		for (int p = length-1; p > idx; p--){
			if (data[idx]>data[p]) dp_right[idx] = max(dp_right[idx], dp_right[p] + 1);
		}
	}
	int answer = 1;
	for (int idx = 0; idx < length; idx++) answer = max(max(answer, dp_left[idx]), dp_right[idx]);
	return answer;
}

int main(){
	int K;
	scanf("%d", &K);
	while (K--){
		int height[N_MAX], length;
		scanf("%d", &length);
		for (int idx = 0; idx < length; idx++) scanf("%d", &height[idx]);
		int answer = calculate_dp2(height, length);
		printf("%d\n", answer);
	}
	return 0;
}