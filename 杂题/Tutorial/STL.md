### STL(Standard Template Library)

**Invoking `sort()`**

```c++
# include <algorithm>
using namespace std; // sort() resides in std;
...
sort(start_address, end_address); // recall library-function sort(); sort() depends on operator <, sorting rules can be defined by overloading // operator <
...
bool cmp(T a, T b) 
{
    ...
}
sort(start_address, end_address, cmp); // if cmp(a, b)==true, then put a ahead of b

stable_sort(); //用法同sort()，但不交换相等元素的先后位置
```

**String**

```c++
#include <string> //注意与string.h的区别
using namesace std;

string s;
cin>>s;

char str[]="test";
s=str;

s+='c';
s+=""string";

string b="class";
s+=b;

string b = "class";
string a = "Two";
if(a==b)
    cout<<a;
if(a<=b)
    cout<<b;

string c = "cout";
cout<<c<<endl;
//printf("%s\b", c.c_str()); //C风格的输出

for(int i = 0; i<s.size(); i++) {
    char c=s[i];
}

s.erase(10,8); //从string对象str中删除从s[10]到s[17]的字符

string a = "asdfsdfadfafd";
string b = "fadf";
int start=0;
int pos = a.find(b, start); //在string中下标start位置开始查找b字符串，若能够找到b字符串则返回其第一次出现的下标；
                            //否则，返回一个常数string::npos. 其中对象b也可以为字=字符数组

string a = "AAAA";
string b = "BBB";
a.insert(2, b);
cout<<a<<endl; //在a中下标为2的字符前插入b字符串，其中string对象b也可以为字符数组
```

**map**

```c++
#include <map>
using namespace

map<string, int> Map;
Map.clear();

if(Map.find(str)==Map.end()) {
    Map[str]=int_a;
}
else
    int_a=Map[str];
```

**堆栈**

```c++
#include <stack>
using namespace std;
...
stack<int> s;

int a, b;
s.push(a);
...
while(!s.empty()) s.pop(); //清空堆栈
...
b=s.top(); 
s.pop();
```

**优先队列(堆)**

```c++
# include <queue>
using namespace std;
...
priority_queue<int> q; //默认建立最大堆，可采用相反数的思路构造小根堆
...
int a, b;
q.push(a);
b=q.top();
q.pop(); //弹出堆顶元素，剩余元素自动调整为新的最小堆
```

**队列**

```c++
#include <queue>
using namespace std;
queue<int> q;
q.push(x);
x=q.front();
q.pop();
q.empty();
```

**邻接表**

```c++
#include <vector>
using namespace std;
...
struct Edge{
    int nextNode;
    int weight;
};
...
vector<Edge> node[N];
...
for(int i=0;i<N;i++) {
    node[i].clear(); //清空单链表
}
...
Edge temp;
temp.nextNode=3;
temp.weight=38;
node[1].push_back(temp);//将该边加入到结点1的单链表中
...
for(int i=0;i<node[2].size();i++) { //遍历所有与结点2相邻的结点
    int nextNode=node[2][i].nextNode;
    int weight=node[2][i].weight;
}
...
node[1].erase(node[1].begin()+i, node[1].begin()+i+1); //删除第i到第i+1个元素（含）
```

