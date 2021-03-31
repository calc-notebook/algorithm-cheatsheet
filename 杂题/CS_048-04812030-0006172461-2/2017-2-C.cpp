#include <iostream>
#include <cstring>
#define N_MAX 10000
using namespace std;

long long process(int* cost, int* sales, int S, int N){
	long long total_cost = 0;
	int storage[N_MAX];
	for (int idx = 0; idx < N; idx++){
		if (idx == 0) storage[idx] = 0;
		else storage[idx] = storage[idx - 1];
		if (storage[idx] < sales[idx]) {
			storage[idx] = 0;
			total_cost += (sales[idx] - storage[idx])* cost[idx];
		}
		else{
			storage[idx] -= sales[idx];
		}
		for (int p = idx + 1; p < N && (cost[idx]+S*(p-idx)<cost[p]); p++){
			storage[idx] += sales[p];
			total_cost += (cost[idx] + S*(p - idx))*sales[p];
		}
	}
	return total_cost;
}

int main(){
	int N, S;
	while (scanf("%d%d", &N, &S) != EOF){
		int cost[N_MAX], sales[N_MAX];
		for (int idx = 0; idx < N; idx++) scanf("%d%d", &cost[idx], &sales[idx]);
		long long answer = process(cost, sales, S, N);
		printf("%lld\n", answer);
	}
	return 0;
}