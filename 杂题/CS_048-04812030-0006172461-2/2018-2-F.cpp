#include <iostream>
#define N_MAX 20000
using namespace std;

int inversion(int* A, int p, int q){
    int sum=0;
    int mid=(p+q)/2;
    if (p==q)   //这个是终止条件，容易忽略
    {
        return 0;
    }

    sum+=inversion(A,p,mid);
    sum+=inversion(A,mid+1,q);

    // 合并思想：用两个临时空间来存储A的两个子序列，然后在求解的过程中排好序再赋值给A
    int m=mid-p+1;
    int n=q-mid;
    int *B=(int*)malloc(sizeof(int)*m);
    int *C=(int*)malloc(sizeof(int)*n);
    int i,j;
    for(i=0;i<m+n;i++)
    {
        if(i<m)
        {
            B[i]=A[i+p];
        }
        else
        {
            C[i-m]=A[i+p];
        }
    }

    i=j=0;
    int k=p;
    while(i<m&&j<n)
    {
        if(B[i]<=C[j])
            A[k++]=B[i++];
        else
        {
            sum+=m-i;
            A[k++]=C[j++];
        }
    }
    if(i==m)
    {
        while(j<n)
            A[k++]=C[j++];
    }
    else
    {
        if(j==n)
        {
            while(i<m)
                A[k++]=B[i++];
        }
    }
    return sum;
}

int main(){
    int N;
    scanf("%d",&N);
    while(N!=0){
        int value[N_MAX];
        for(int idx=0;idx<N;idx++) scanf("%d",&value[idx]);
        int answer=inversion(value,0,N-1);
        printf("%d\n",answer);
        scanf("%d",&N);
    }

    return 0;
}

