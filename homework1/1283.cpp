#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m, d[N][N], mp[N][N];

int v[1010], len;
void mul2() {
	int tmp = 0;
	for(int i = 1; i <= len; i ++) {
		v[i] = (v[i] << 1) + tmp;
		tmp = v[i] / 10;
		v[i] %= 10;
	}
	while(tmp) {
		v[++ len] = tmp % 10;
		tmp /= 10;
	}
}

int fa[N];
int getfa(int x) {return fa[x] == x ? x : fa[x] = getfa(fa[x]);}
int main() {
	v[1] = len = 1;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int f1 = getfa(x), f2 = getfa(y);
		if (f1 != f2) {
			ans ++;
			fa[f1] = f2;
		}
	}
	ans = 20;
	for(int i = 1; i <= ans; i ++) mul2();
	for(int i = len; i; i --) printf("%d", v[i]);
	return 0;
}

