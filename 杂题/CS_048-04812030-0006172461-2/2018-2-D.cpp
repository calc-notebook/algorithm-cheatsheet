#include <iostream>
#include <cmath>
#include <algorithm>

#define N_MAX 1000

using namespace std;

int R; // the radius

class Point{
public:
    int x, y;
    double a, b;
    void calculate()
    {
        double dx = sqrt(pow(R,2)-pow(y,2));
        a = x - dx;
        b = x + dx;
    }
    bool operator<(const Point &p) const {
        if(b<p.b) return true;
        else return false;
    }
};

int main(){
    int N;
    Point points[N_MAX];
    scanf("%d%d",&N,&R);
    int caseNum=1;
    while(!(N==0&& R==0))
    {
        int max_y=0;
        for(int idx=0; idx<N; idx++)
        {
            scanf("%d%d",&points[idx].x, &points[idx].y);
            if(points[idx].y>max_y) max_y=points[idx].y;
            points[idx].calculate();
        }

        if(max_y>R)
        {
            printf("Case %d: -1\n",caseNum);
            caseNum++;
            scanf("%d%d",&N,&R);
            continue;
        }
        sort(points,points+N);

        int cnt=1;
        double tail=points[0].b;
        for(int idx=1;idx<N;idx++)
        {
            if(points[idx].a>tail)
            {
                cnt++;
                tail=points[idx].b;
            }
        }
        printf("Case %d: %d\n",caseNum, cnt);
        caseNum++;
        scanf("%d%d",&N,&R);
    }
    return 0;
}