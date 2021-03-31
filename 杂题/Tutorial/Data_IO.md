### Standard I/O

由于类C风格输入输出耗时明显小于`cin`和`cout`，在机试中较为推荐.

**Loop Control**

The input contains several test cases. Every test case starts with three integers N1, N2, D.  The last test case is followed by three zeros.

```c++
int N1, N2, D;
while(scanf("%d%d%d",&N1,&N2,&D)!=EOF && !(N1==0 && N2 ==0 && D==0)){
    
}
```

**Read `20190113` to `year`, `month` and `day`**

```c++
struct {
    int year, month, day;
}data;

scanf("%4d%2d%2d", &data.year, &data.month, &data.day); // input date
```

**Read `string` to `char*` array**

```c++
char str[20];
string str_;
scanf("%s",str);
str_ = str; //将字符数组赋值给string，因为用scanf()直接输入string比较繁琐
```

**Read other data type**

```c++
char c;
scanf("%c", &c); //输入char

long long b;
scanf("%lld", &b); //输入64bit长整数

double d;
scanf("%f", &d); //输入double
```

**Print**

```c++
printf("%d %c", a,c); //输出int, char
prinf("lld", b); //输出64bit长整形
printf("%.2f"); //输出固定精度的double
//prinf()和cout不要混用
```

