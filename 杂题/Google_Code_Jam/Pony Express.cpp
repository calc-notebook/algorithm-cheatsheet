/*
Google Code Jam, Round 1B 2017, Problem C. Pony Express
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard#s=p2
��Դ���·��
Completed, By Gao Shuqi, on 2018-04-16.

Lessons to Learn:
��������������û�����Գ���int��ʾ��Χ����ֵ��ҲҪע������������Ƿ���ܷ������
*/

#include <iostream>
#define N_MAX 100
using namespace std;

int N, Q;
struct City{
	int E, S;
}city[N_MAX + 1];

long long map[N_MAX + 1][N_MAX + 1];
double map_[N_MAX + 1][N_MAX + 1];
int U[100], V[100];

double min(double a, double b) { return (a < b) ? a : b; }

int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &N, &Q);
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &city[i].E, &city[i].S);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				scanf("%lld", &map[i][j]);
		}
		for (int k = 0; k < Q; k++) scanf("%d%d", &U[k], &V[k]);
		//����ԭͼG�и������С����
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (map[i][k] == -1 || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][k] + map[k][j] < map[i][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
		//������ͼG'
		double ans[N_MAX + 1][N_MAX + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) ans[i][j] = 0;
				else if (map[i][j] == -1 || map[i][j]>city[i].E) ans[i][j] = -1;
				else ans[i][j] = double(map[i][j]) / city[i].S;
			}
		}
		//������ͼG'�и�������С����
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (ans[i][k] == -1 || ans[k][j] == -1) continue;
					if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
						ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
		
		printf("Case #%d:", ii);
		for (int k = 0; k < Q; k++) {
			//����U[k]��V[k]����Сʱ�俪��������ֵ��ans
			double ans_ = ans[U[k]][V[k]];
			printf(" %.8f", ans_);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}