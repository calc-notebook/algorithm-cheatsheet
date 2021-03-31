/*
Google Code Jam, Practice Session 2018, Problem A. Number Guessing
Retrieved from https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard#!
Finished, By Gao Shuqi, on 2018-03-31.
*/

#include <iostream>
#include<string>
using namespace std;

int A, B, N, bottom, top, mid;
string str, correct = "CORRECT", smaller = "TOO_SMALL", bigger = "TOO_BIG", wrong = "WRONG_ANSWER";

int main() {
	int T;
	cin>>T;
	for (int ii = 1; ii <= T; ii++) {
		cin>>A>>B;
		cin>>N;
		int k = 0;
		bottom = A + 1;
		top = B;
		int tmp=0;
		while (++k <= N) {
			mid = (top + bottom) / 2;
			if (bottom == top) cout<<bottom<<endl;
			else{
				cout << mid << endl;
			}
			cin>>str;
			if (str == correct) tmp=0;
			else if (str == smaller) tmp= -1;
			else if (str == bigger) tmp=1;
			else tmp= -2;
			if (tmp == 0) break;
			if (tmp == 1) { top = mid - 1; continue; }
			if (tmp == -1) { bottom = mid + 1; continue; } 
			if (tmp == -2) break;
		}
		if (tmp != 0) break;
	}
	return 0;
}