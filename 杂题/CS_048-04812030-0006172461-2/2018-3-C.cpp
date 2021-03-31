//
// Created by Sukie on 11/18/2018.
//
#include <iostream>
#include <string>
#define N_MAX 201
using namespace std;

int dp[N_MAX][N_MAX];

int max(int a, int b) { return (a>b) ? a : b; }

int main(){
    string S1, S2;
    while (cin >> S1 >> S2){
        int n = S1.length();
        int m = S2.length();
        for (int idx = 0; idx<n; idx++) dp[idx][0] = 0;
        for (int idx = 0; idx<m; idx++) dp[0][idx] = 0;
        for (int idx1 = 1; idx1 <= n; idx1++){
            for (int idx2 = 1; idx2 <= m; idx2++){
                if (S1[idx1 - 1] == S2[idx2 - 1]) dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
                else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        int answer = 0;
        for (int idx1 = 1; idx1 <= n; idx1++)
            for (int idx2 = 1; idx2 <= m; idx2++)
                answer = max(answer, dp[idx1][idx2]);
        printf("%d\n", answer);
    }
    return 0;
}