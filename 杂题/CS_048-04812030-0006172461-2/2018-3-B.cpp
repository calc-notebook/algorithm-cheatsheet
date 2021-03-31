//
// Created by Sukie on 11/18/2018.
//
#include <iostream>
#define N_MAX 100
using namespace std;

int heights[N_MAX];

int dp_left[N_MAX];
int dp_right[N_MAX];

int max(int a, int b) { return (a>b) ? a : b; }

int main(){
    int N;
    scanf("%d", &N);
    for (int idx = 0; idx<N; idx++) {
        scanf("%d", &heights[idx]);
        dp_left[idx] = 0;
        dp_right[idx] = 0;
    }

    dp_left[0] = 1;
    for (int idx = 1; idx<N; idx++){
        int temp_max = 1;
        for (int p = 0; p<idx; p++){
            if (heights[p]<heights[idx]) temp_max = max(temp_max, dp_left[p] + 1);
        }
        dp_left[idx] = temp_max;
    }

    dp_right[N - 1] = 1;
    for (int idx = N - 2; idx >= 0; idx--){
        int temp_max = 1;
        for (int p = N - 1; p>idx; p--){
            if (heights[p]<heights[idx]) temp_max = max(temp_max, dp_right[p] + 1);
        }
        dp_right[idx] = temp_max;
    }


    int answer = 0;
    for (int idx = 0; idx<N; idx++){
        answer = max(answer, dp_left[idx] + dp_right[idx]-1);
    }

    printf("%d\n", N - answer);

    return 0;
}

