#include <iostream>
#include <algorithm>

struct region {
    int a,b;
};

bool compare(region a, region b)
{
    if(a.a<b.a) return true;
    else if(a.a==b.a) return a.b<b.b;
    else return false;
}

int main(int argc, char* argv[])
{
    int N;
    scanf("%d",&N);
    region data[50000];
    for(int idx=0;idx<N;idx++) std::cin>>data[idx].a>>data[idx].b;
    std::sort(data,data+N,compare);
    bool isCombined=true;
    int a,b;
    a=data[0].a;
    b=data[0].b;
    for(int idx=1;idx<N;idx++)
    {
        if(data[idx].a>b) {isCombined=false;break;}
        b=b>data[idx].b?b:data[idx].b;
    }
    if(isCombined) std::cout<<a<<" "<<b<<std::endl;
    else std::cout<<"no"<<std::endl;

    return 0;
}
