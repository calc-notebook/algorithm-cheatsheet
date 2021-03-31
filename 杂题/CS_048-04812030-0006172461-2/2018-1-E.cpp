#include <iostream>
#define N_MAX 65536

int pre[N_MAX],cnt;

void process(int* mid, int* post, int length)
{
    int pos=0;
    for(;pos<length && mid[pos]!=post[length-1];pos++);
    pre[cnt++]=mid[pos];
    if(pos>0)
    {
        process(mid,post,pos);
    }
    if(pos<length-1)
    {
        process(mid+pos+1,post+pos,length-pos-1);
    }
}
int main(int argc, char* argv[])
{
    int mid[N_MAX], post[N_MAX];
    int N;

    for(N=0;;N++)
    {
        scanf("%d",&mid[N]);
        if(getchar()!=' ') break;
    }
    for(N=0;;N++)
    {
        scanf("%d",&post[N]);
        if(getchar()!=' ') break;
    }

    cnt=0;
    process(mid,post,++N);

    std::cout<<pre[0];
    for(int idx=1;idx<cnt;idx++) std::cout<<" "<<pre[idx];
    std::cout<<std::endl;

    return 0;
}
