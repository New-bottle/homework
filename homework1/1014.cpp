#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;
const int Limit = 10;

struct Bint{
	int v[N], len;
	Bint(){
		memset(v, 0, sizeof v);
		len = 0;
	}
	Bint(char *s){
		len = strlen(s);
		for(int i = 1; i <= len; i ++)
			v[i] = s[len - i] - '0';
	}
	int& operator [] (int x) {return v[x];}
	friend Bint operator + (const Bint &a, const Bint &b) {
		Bint c;
		int len = max(a.len, b.len), tmp = 0;
		for(int i = 1; i <= len; i ++) {
			c[i] = a.v[i] + b.v[i] + tmp;
			tmp = c[i] / Limit;
			c[i] %= Limit;
		}
		if (tmp) c[++len] = tmp;
		c.len = len;
		return c;
	}
	void print() {
		printf("%d", v[len]);
		for(int i = len - 1; i; i--)
			printf("%d", v[i]);
	}
};

char s1[100010], s2[100010];

int main() {
	scanf("%s%s", s1, s2);
	Bint a(s1), b(s2);
//	a.print();
//	b.print();
	(a + b).print();
	return 0;
}
