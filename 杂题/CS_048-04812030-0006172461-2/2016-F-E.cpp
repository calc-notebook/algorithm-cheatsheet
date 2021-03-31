#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 200000 + 1;

long long divide_and_conquer(int* data, int length){
	if (length == 1) return 0;
	int mid = length / 2;
	long long answer = 0;
	answer += divide_and_conquer(data, mid);
	answer += divide_and_conquer(data + mid, length - mid);
	for (int i = 0, j = mid; i < mid && j < length;){
		if (data[i] > 2 * data[j]) { answer += (mid - i); j++; }
		else { i++; }
	}
	inplace_merge(data, data + mid, data + length);
	return answer;
}

int main(){
	int data[N_MAX], N;
	while (scanf("%d", &N) != EOF && N != 0){
		for (int i = 0; i < N; i++) scanf("%d", &data[i]);
		long long answer = divide_and_conquer(data, N);
		printf("%lld\n", answer);
	}
	return 0;
}