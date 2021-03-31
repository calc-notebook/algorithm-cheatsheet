#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define N_MAX 1000

using namespace std;

class Edge{
public:
    int nextNode;
    int cost;
};

class Graph{
public:
    vector<Edge> point[N_MAX];
};

int main(){
    int  N, M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Graph graph;

        for(int idx=0;idx<M;idx++)
        {
            int a, b, r;
            scanf("%d%d%d",&a,&b,&r);
            Edge newEdge;
            newEdge.cost=r;
            newEdge.nextNode=b;
            graph.point[a].push_back(newEdge);
            newEdge.nextNode=a;
            graph.point[b].push_back(newEdge);
        }

        int label[N_MAX];
        for(int idx=0; idx<N; idx++) label[idx]=-1;
        bool isClassified=true;

        for(int idx=0;idx<N;idx++)
        {
            if(label[idx]!=-1) continue;
            label[idx]=0;

            queue<int> q; q.empty();q.push(idx);
            while(!q.empty())
            {
                int curPoint=q.front(); q.pop();
                for(int p=0;p<graph.point[curPoint].size();p++)
                {
                    if(label[graph.point[curPoint][p].nextNode]!=-1
                    && label[graph.point[curPoint][p].nextNode]==(label[curPoint]+graph.point[curPoint][p].cost)%2)
                        continue;
                    if(label[graph.point[curPoint][p].nextNode]!=-1
                    && label[graph.point[curPoint][p].nextNode]!=(label[curPoint]+graph.point[curPoint][p].cost)%2)
                    {
                        isClassified=false;
                        break;
                    }
                    if(graph.point[curPoint][p].cost==0) label[graph.point[curPoint][p].nextNode]=label[curPoint];
                    else label[graph.point[curPoint][p].nextNode]=(label[curPoint]+1)%2;
                    q.push(graph.point[curPoint][p].nextNode);
                }
                if(!isClassified) break;
            }
            if(!isClassified) break;
        }
        if(isClassified) printf("YES\n");
        else printf("NO\n");
    }

}