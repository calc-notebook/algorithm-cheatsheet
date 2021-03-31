#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 10;
const int INF = 1000000000;
const double pi = 3.141592653589;
long long n, m;
long long a[maxn], mina, sum;
long long solve(long long L, long long R)
{
	const long long mid = (L + R) / 2;
	if (L == R)return mid;
	long long i, x, y;
	for (i = 0, x = a[i], y = 0; i<n; i++, x += a[i]){
		if (x>mid){
			x = a[i];
			y++;
		}
	}
	if (y<m)return solve(L, mid);
	else return solve(mid + 1, R);
}
int main()
{
	cin >> n >> m;
	sum = 0;
	mina = 0;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
		mina = max(a[i], mina);
		sum += a[i];
	}
	printf("%lld\n", solve(mina, sum));
	return 0;
}