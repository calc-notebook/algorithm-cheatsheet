#include <iostream>
#include <queue>

using namespace std;

class DynamicMedian{
private:
    priority_queue<int, vector<int>, less<int>> left; // Big-end Heap
    priority_queue<int, vector<int>, greater<int>> right; // Small-end Heap
    int cnt_left;
    int cnt_right;
    void balance(){
        if(abs(cnt_left-cnt_right)<=1) return;
        while(cnt_left-cnt_right>1)
        {
            int temp=left.top();
            left.pop();
            cnt_left--;
            right.push(temp);
            cnt_right++;
        }
        while(cnt_right-cnt_left>1)
        {
            int temp=right.top();
            right.pop();
            cnt_right--;
            left.push(temp);
            cnt_left++;
        }

    }
public:
    void init()
    {
        cnt_left=0;
        cnt_right=0;
        while(!left.empty()) left.pop();
        while(!right.empty()) right.pop();
    }

    void insert(int value)
    {
        if(cnt_left==0 && cnt_right==0){
            left.push(value);
            cnt_left++;
        }
        else if(cnt_left==0 && cnt_right!=0){
            if(value<=right.top()){
                left.push(value);
                cnt_left++;
                balance();
            }
            else{
                right.push(value);
                cnt_right++;
                balance();
            }
        }
        else if(cnt_left!=0 && cnt_right==0){
            if(value>=left.top()){
                right.push(value);
                cnt_right++;
                balance();
            }
            else{
                left.push(value);
                cnt_left++;
                balance();
            }
        }
        else{
            if(value>=left.top()){
                right.push(value);
                cnt_right++;
                balance();
            }
            else{
                left.push(value);
                cnt_left++;
                balance();
            }
        }
    }
    void remove()
    {
        if(cnt_left>=cnt_right)
        {
            left.pop();
            cnt_left--;
            balance();
        }
        else
        {
            right.pop();
            cnt_right--;
            balance();
        }
    }
    int query()
    {
        if(cnt_left>=cnt_right)
        {
            return left.top();
        }
        else
        {
            return right.top();
        }
    }

};



int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        DynamicMedian dynamicMedian;
        dynamicMedian.init();
        while(N--)
        {
            char op;
            getchar();
            scanf("%c",&op);
            if(op=='I')
            {
                int value;
                scanf("%d",&value);
                dynamicMedian.insert(value);
            }
            else if(op=='Q')
            {
                int value = dynamicMedian.query();
                printf("%d\n",value);
            }
            else if(op=='D')
            {
                dynamicMedian.remove();
            }
            else
            {
//                printf("wrong operations");
            }
        }
    }
    return 0;
}