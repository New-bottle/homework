#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300010;

int n, m, rt[N];
priority_queue<int, vector<int>, greater<int> > Q[N];

void init() 
{
	for(int i = 0; i < n; ++i) {
		rt[i] = i;
		int x;
		scanf("%d", &x);
		Q[i].push(x);
	}
}
void solve() 
{
	int opt, x, y;
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &opt);
		if (opt == 0) {
			scanf("%d%d", &x, &y);
			if (Q[rt[x]].size() < Q[rt[y]].size()) swap(rt[x], rt[y]);
			while(Q[rt[y]].size()) {
				Q[rt[x]].push(Q[rt[y]].top());
				Q[rt[y]].pop();
			}
			rt[y] = rt[x];
		} else if (opt == 1) {
			scanf("%d", &x);
			if (Q[rt[x]].empty()) {
				puts("-1");
				continue;
			} else {
				printf("%d\n", Q[rt[x]].top());
				Q[rt[x]].pop();
			}
		} else if (opt == 2) {
			scanf("%d%d", &x, &y);
			Q[rt[x]].push(y);
		}
	}
}
int main() 
{
	scanf("%d%d", &n, &m);
	init();
	solve();
	return 0;
}
