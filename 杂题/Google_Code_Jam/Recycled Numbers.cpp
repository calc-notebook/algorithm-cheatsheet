/*
Google Code Jam, Qualification Round 2012, Problem C. Recycled Numbers
Retrieved from https://code.google.com/codejam/contest/1460488/dashboard#s=p2
Finished, By Gao Shuqi, on 2018-04-01.
*/

#include <iostream>
using namespace std;

char bottom[20], top[20],tmp[20];
int N;

int num2str(int a, int b) {
	int length = 0;
	while (b != 0) {
		bottom[length] = a % 10 + '0';
		top[length++] = b % 10 + '0';
		a /= 10;
		b /= 10;
	}
	return length;
}

void num2str(int d) {
	int length = 0;
	while (d != 0) {
		tmp[length++] = d % 10 + '0';
		d /= 10;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int A, B;
		scanf("%d%d", &A, &B);
		int length=num2str(A,B);
		for (int i = A; i <= B; i++) {

		}

	}
	return 0;
}