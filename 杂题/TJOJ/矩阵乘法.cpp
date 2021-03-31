/*
Tongji OJ, Problem 1079. 矩阵乘法
Retrieved from http://acm.tongji.edu.cn/problem.php?id=1079
矩阵计算, 二分求幂
Completed, By Gao Shuqi, on 2018-04-10

Lessons to Learn
有些编译器不识别'\b'，慎用
*/
#include <iostream>
using namespace std;

int N, M;
int in[30][30], out2[30][30], out3[30][30], out4[30][30], out5[30][30], out0[30][30];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &in[i][j]);
		}
	}
	if (M == 0)  {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) out0[i][j] = 1;
				else out0[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			printf("%d", out0[i][0]);
			for (int j = 1; j < N; j++) {
				printf(" %d", out0[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	if (M == 1)  {
		for (int i = 0; i < N; i++) {
			printf("%d", in[i][0]);
			for (int j = 1; j < N; j++) {
				printf(" %d", in[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) tmp += in[i][k] * in[k][j];
			out2[i][j] = tmp;
		}
	}
	if (M == 2)  {
		for (int i = 0; i < N; i++) {
			printf("%d", out2[i][0]);
			for (int j = 1; j < N; j++) {
				printf(" %d", out2[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	if (M == 3)  {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp = 0;
				for (int k = 0; k < N; k++) tmp += in[i][k] * out2[k][j];
				out3[i][j] = tmp;
			}
		}

		for (int i = 0; i < N; i++) {
			printf("%d", out3[i][0]);
			for (int j = 1; j < N; j++) {
				printf(" %d", out3[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) tmp += out2[i][k] * out2[k][j];
			out4[i][j] = tmp;
		}
	}
	if (M == 4)  {
		for (int i = 0; i < N; i++) {
			printf("%d", out4[i][0]);
			for (int j = 1; j < N; j++) {
				printf(" %d", out4[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) tmp += in[i][k] * out4[k][j];
			out5[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d", out5[i][0]);
		for (int j = 1; j < N; j++) {
			printf(" %d", out5[i][j]);
		}
		printf("\n");
	}
	return 0;
}