#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define N_MAX 501
using namespace std;

class Edge{
public:
	short next_field;
	short time_consume;
};
class Dist{
public:
	int identity;
	int distance;
};
int F, P, C, M;
vector<Edge> path[N_MAX];
int position[N_MAX];
int dist[N_MAX];

//auto cmp = [](Dist left, Dist right){return left.distance < right.distance; };
//bool cmp(Dist a, Dist b){ return a.distance < b.distance; }
struct DereferenceCompareNode : public std::binary_function<Dist, Dist, bool>
{
	bool operator()(const Dist lhs, const Dist rhs) const
	{
		return lhs.distance < rhs.distance;
	}
};

void process(){
	//priority_queue<Dist, vector<Dist>, decltype(cmp)> minHeap(cmp);
	//priority_queue<Dist, vector<Dist>, greater<vector<Dist>::value_type>> minHeap;
	priority_queue<Dist, vector<Dist>, DereferenceCompareNode> minHeap;
	Dist addedDist; addedDist.distance = 0; addedDist.identity = 1;
	dist[1] = 0;
	minHeap.push(addedDist);
	addedDist.distance = 1e7;
	for (int idx = 2; idx <= F; idx++){
		addedDist.identity = idx;
		minHeap.push(addedDist);
		dist[idx] = 1e7;
	}
	while (!minHeap.empty()){
		if (minHeap.top().distance!=dist[minHeap.top().identity]) { minHeap.pop(); continue; }
		Dist retrivedDist = minHeap.top();
		minHeap.pop();
		for (int idx = 0; idx < path[retrivedDist.identity].size(); idx++){
			if (dist[path[retrivedDist.identity][idx].next_field]>
				dist[retrivedDist.identity] + path[retrivedDist.identity][idx].time_consume)
				dist[path[retrivedDist.identity][idx].next_field] = dist[retrivedDist.identity] + path[retrivedDist.identity][idx].time_consume;
		}
	}
	int answer[N_MAX], cnt = 0;
	for (int idx = 1; idx <= C; idx++){
		if (dist[position[idx]] <= M) answer[cnt++] = idx;
	}
	sort(answer, answer+cnt);
	printf("%d\n", cnt);
	for (int idx = 0; idx < cnt; idx++) printf("%d\n", answer[idx]);
}

int main(){
	scanf("%d%d%d%d", &F, &P, &C, &M);
	for (int idx = 1; idx <= P; idx++){
		Edge addedEdge;
		short a, b;
		scanf("%d%d%d", &a, &b, &addedEdge.next_field);
		addedEdge.next_field = b;
		path[a].push_back(addedEdge);
		addedEdge.next_field = a;
		path[b].push_back(addedEdge);
	}
	for (int idx = 1; idx <= C; idx++) scanf("%d", &position[idx]);
	process();
	return 0;
}