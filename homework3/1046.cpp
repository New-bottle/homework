#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, p, q, l[N], r[N], size[N], a[N], cnt, st[N], ed[N], pos[N];
int v[N];
bool yes[N], can[N];

inline int lowbit(int x) {return x & (-x);}
void add(int x) {
	for(int i = x; i <= n; i += lowbit(i)) v[i] ++;
}
int sum(int x) {
	if (!x) return 0;
	int r = 0;
	for(int i = x; i; i -= lowbit(i)) r += v[i];
	return r;
}

void dfs(int x) {
//	printf("dfs %d\n", x);
	st[x] = cnt + 1;
	if (l[x]) dfs(l[x]);
	a[++cnt] = x;
	pos[x] = cnt;
	if (r[x]) dfs(r[x]);
	size[x] = size[l[x]] + size[r[x]] + 1;
	ed[x] = cnt;
}

int main() {
	scanf("%d%d%d", &n, &p, &q);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		scanf("%d%d", &l[x], &r[x]);
		can[l[x]] = can[r[x]] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		if (!can[i]) dfs(i);
	}
//	for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
	for(int i = 1; i <= p; ++i) {
		int t, x;
		scanf("%d%d", &t, &x);
		int who = a[st[t] + (x % size[t])];
//		printf("who = %d\n", who);
		if (yes[who]) continue;
		yes[who] = 1;
		add(pos[who]);
	}
	for(int i = 1; i <= q; ++i) {
		int x;
		scanf("%d", &x);
		printf("%d\n", sum(st[x] + size[x] - 1) - sum(st[x] - 1));
	}
	return 0;
}
