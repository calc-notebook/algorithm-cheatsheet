#include <iostream>
#include <algorithm>
#include <cstring>

#define N_MAX 101

using namespace std;

int root[N_MAX];
int findRoot(int a) {
    if(root[a]==-1) return a;
    int real_root=findRoot(root[a]);
    root[a]=real_root;
    return root[a];
}

class Edge{
public:
    int start;
    int end;
    int cost;
    bool operator<(Edge anotherEdge) const{
        return this->cost<anotherEdge.cost;
    }
};

int main(){
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        Edge edges[N_MAX*N_MAX];
        int cnt=0;
        int answer=0;
        for(int idx1=1;idx1<=N;idx1++)
        {
            for(int idx2=1;idx2<=N;idx2++)
            {
                Edge newEdge;
                newEdge.start=idx1;
                newEdge.end=idx2;
                scanf("%d",&newEdge.cost);
                if(idx1>=idx2) continue;
                edges[cnt++]=newEdge;

            }
            root[idx1]=-1;
        }
        // Find solutions
        sort(edges,edges+cnt);
        for(int idx=0;idx<cnt;idx++){
            int a_root=findRoot(edges[idx].start);
            int b_root=findRoot(edges[idx].end);
            if(a_root==b_root) continue;
            root[a_root]=b_root;
            answer+=edges[idx].cost;
        }
        printf("%d\n",answer);
    }
    return 0;
}
