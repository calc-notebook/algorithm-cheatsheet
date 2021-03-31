#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
char s[10];
double f(){
	scanf("%s", s);
	switch (s[0]){
	case '+': return f() + f();
	case '-': return f() - f();
	case '*': return f() * f();
	case '/': return f() / f();
	default: return atof(s);
	}
}

int main(){
	printf("%f\n", f());
	return 0;
}