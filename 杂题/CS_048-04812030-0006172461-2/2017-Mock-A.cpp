#include <iostream>
#define N_MAX 1000
using namespace std;

class Vehicle{
public:
	int weight;
	int speed;
};

int min(int a1, int a2) { return (a1 < a2) ? a1 : a2; }

int b, l;

double calShortestTime(Vehicle *vehicle, int length){
	if (length == 1) return double(l) / vehicle[0].speed;
	double dp[N_MAX];
	dp[0] = double(l) / vehicle[0].speed;
	for (int idx = 1; idx < length; idx++){
		double accumulated_weight = vehicle[idx].weight;
		double slow_speed = vehicle[idx].speed;
		dp[idx] = (double)l / vehicle[idx].speed + dp[idx - 1];
		for (int p = idx - 1; p >= 0 && vehicle[p].weight + accumulated_weight <= b; p--){
			slow_speed = min(slow_speed, (double)vehicle[p].speed);
			dp[idx] = min(dp[idx], (double)l / slow_speed + dp[p - 1]);
			accumulated_weight += vehicle[p].weight;
		}
	}
	return dp[length - 1];
}

int main(){
	int n; // b-bridge sustain, l-bridge length, n-number of vehicle
	while (scanf("%d%d%d", &b, &l, &n) != EOF && !(b == 0 && l == 0 && n == 0)){
		Vehicle vehicles[N_MAX];
		for (int idx = 0; idx < n; idx++) scanf("%d%d", &vehicles[idx].weight,
			&vehicles[idx].speed);
		double answer = calShortestTime(vehicles, n);
		printf("%.1f\n", answer * 60);
	}
	return 0;
}
