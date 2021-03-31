#include <iostream>

void process(int num, char src, char dst, char buf)
{
    if(num==1)
    {
        printf("%d:%c->%c\n",num,src,dst);
    }
    else
    {
        process(num-1,src,buf,dst);
        printf("%d:%c->%c\n",num,src,dst);
        process(num-1,buf,dst,src);
    }
}

int main(int argc, char* argv[])
{
    int N;
    scanf("%d",&N);
    char name[3];
    std::cin>>name[0]>>name[1]>>name[2];
    process(N,name[0],name[2],name[1]);
    
    return 0;
}
