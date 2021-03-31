#include <iostream>

int main(int argc, char* argv[])
{
    int T;
    scanf("%d",&T);
    while(T-->0)
    {
        int N, data[1000];
        bool poped[1000];
        scanf("%d",&N);
        for(int idx=0;idx<N;idx++) {std::cin>>data[idx];poped[idx]=false;}
        bool isPossible=true;
        for(int i=0;i<N-1;i++)
        {
            int nearMaxPos=i+1;
            for(;nearMaxPos<N && data[nearMaxPos]<data[i];nearMaxPos++);
            if(nearMaxPos==i+1) continue;
            else if(nearMaxPos==N)
            {
                for(int p=i+1;p<N-1;p++){
                    if(data[p]<=data[p+1]){isPossible=false; break;}
                }
            }
            else
            {
                for(int p=i+1;p<nearMaxPos-1;p++){
                    if(data[p]<=data[p+1]){isPossible=false; break;}
                }
            }
           if(!isPossible) break;
        }

        if(isPossible) std::cout<<"yes"<<std::endl;
        else std::cout<<"no"<<std::endl;
    }
    return 0;
}
