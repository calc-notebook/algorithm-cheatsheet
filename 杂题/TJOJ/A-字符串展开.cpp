/*
Tongji OJ, Problem 1064. A-字符串展开
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1064
字符串
Completed, By Gao Shuqi, on 2018-04-19.
*/

#include <iostream>
#include <string.h>
#define N_MAX 1000
using namespace std;

int main() {
	char str_in[N_MAX];
	char str_out[N_MAX];
	int poc;
	while (gets(str_in) != 0) {
		poc = 0;
		int N = strlen(str_in);
		for (int i = 0; i < N; i++) {
			if (str_in[i] >= '1' && str_in[i] <= '9') {
				int tmp = str_in[i] - '1';
				for (int j = 0; j < tmp; j++) str_out[poc++] = str_in[i - 1];
			}
			else str_out[poc++] = str_in[i];
		}
		for (int i = 0; i < poc; i++) printf("%c", str_out[i]);
		printf("\n");
	}
	return 0;
}