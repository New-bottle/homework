#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10100;

char s1[N], s2[N];
int a[N], b[N], c[N];
int change(char *s, int *a) {
	int l = strlen(s);
	for(int i = 0; i < l; ++ i)
		a[l - i] = s[i] - '0';
	return l;
}
int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	int l1 = change(s1, a), l2 = change(s2, b);
//	for(int i = l1; i; i --) printf("%d", a[i]); puts("");
//	for(int i = l2; i; i --) printf("%d", b[i]); puts("");
	for(int i = 1; i <= l1; i ++)
		for(int j = 1; j <= l2; j ++)
			c[i + j - 1] += a[i] * b[j];
	int tmp = 0, l = l1 + l2 - 1;
	for(int i = 1; i <= l; i ++) {
		c[i] += tmp;
		tmp = c[i] / 10;
		c[i] %= 10;
	}
	while(tmp) {
		c[++ l] = tmp % 10;
		tmp /= 10;
	}
	for(int i = l; i; i --) printf("%d", c[i]); puts("");
	return 0;
}
