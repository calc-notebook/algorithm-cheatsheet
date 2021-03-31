#include <iostream>
#include <cstring>
#include <vector>

int main(){
    int N, data[200];
    char instr[200], outstr[200];
    scanf("%d",&N);
    while(N!=0)
    {
        for(int idx=0;idx<N;idx++)
        {
            int temp;
            std::cin>>temp;
            data[idx]=temp-1;
        }
//=== ANALYSIS CYCLE ===
        std::vector<int> prior[200];
        for(int idx=0;idx<N;idx++)
        {
            for(int nextPos=idx;
            prior[idx].empty() ||
            nextPos!=prior[idx].front();
            prior[idx].push_back(nextPos),
            nextPos=data[nextPos]);
        }
//=== END ANALYSIS CYCLE ===

        int k;
        std::cin>>k;
        while(k!=0)
        {
            getchar();
            gets(instr);

            memset(outstr,' ',N);
            int length=0;
            for(int idx=0;idx<strlen(instr);idx++)
            {
                int T=prior[idx].size();
                length=(prior[idx].at(k%T)>length)?prior[idx].at(k%T):length;
                outstr[prior[idx].at(k%T)]=instr[idx];
            }

            for(int idx=0;idx<=length;idx++) std::cout<<outstr[idx];
            std::cout<<std::endl;
            std::cin>>k;
        }
        std::cout<<std::endl;
        std::cin>>N;
    }
    return 0;
}
