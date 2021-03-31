#include <iostream>
#include <cstring>
#include <vector>

#define N_MAX 1000

using namespace std;

bool visited[N_MAX+1][N_MAX+1];

int root[N_MAX*N_MAX+2];
int getRoot(int idx){
    if(root[idx]==-1) return idx;
    int ancestor=getRoot(root[idx]);
    root[idx]=ancestor;
    return ancestor;
}

int neighbor[4][2]={-1,0,+1,0,0,-1,0,+1};

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N, M;
        scanf("%d%d",&N,&M);
        for(int idx=0;idx<=N*N+1;idx++) root[idx]=-1;
        memset(visited,0,(N_MAX+1)*(N_MAX+1));
        int number=-1;
        for(int idx=0;idx<M;idx++){
            int x, y;
            scanf("%d%d",&x, &y);
            if(number!=-1) continue;
            visited[x][y]=true;
// The first round
            if(x==1) root[(x-1)*N+y]=0;
            for(int p=0;p<4;p++){
                int x_next=x+neighbor[p][0];
                int y_next=y+neighbor[p][1];
                if(!(x_next<1 || x_next>N || y_next<1 || y_next>N)) {
                    if(!visited[x_next][y_next]) continue;
                    if(root[(x-1)*N+y]==-1){
                        root[(x-1)*N+y]=getRoot((x_next-1)*N+y_next);
                    }
                    else{
                        int root_a=getRoot((x_next-1)*N+y_next);
                        int root_b=getRoot((x-1)*N+y);
                        if(root_a<root_b){
                            root[root_b]=root_a;
                        }
                        if(root_a>root_b){
                            root[root_a]=root_b;
                        }
                    }
                }
            }
            if(x==N) {
                int root_a=getRoot((x-1)*N+y);
                int root_b=getRoot(N*N+1);
                if(root_a<root_b){
                    root[root_b]=root_a;
                }
                if(root_a>root_b){
                    root[root_a]=root_b;
                }
            }
// The second round
            for(int p=0;p<4;p++){
                int x_next=x+neighbor[p][0];
                int y_next=y+neighbor[p][1];
                if(x_next>=1 && x_next<=N && y_next>=1 && y_next<=N && visited[x_next][y_next]
                &&root[(x_next-1)*N+y_next]!=-1){
                    root[(x_next-1)*N+y_next]=getRoot((x-1)*N+y);
                }
            }
            if(x==N){
                root[N*N+1]=getRoot((x-1)*N+y);
            }

            if(idx<N) continue;
            if(getRoot(N*N+1)==0) number=idx+1;
        }
        printf("%d\n",number);
    }

    return 0;
}