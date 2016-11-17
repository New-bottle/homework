#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

char s[N * 10];
set<int> son[N];
int n, st[N], du[N], fa[N];
priority_queue<int, vector<int>, greater<int> >Q;

int main() 
{
	gets(s);
	int n = strlen(s), top = 0, m = 0;
	for(int i = 0; i < n; ++i) {
		if (s[i] == ' ') continue;
		if (s[i] == '(') {
			++i;
			int now = 0;
			while(s[i] >= '0' && s[i] <= '9') {
				now = now * 10 + s[i] - '0';
				++i;
			}
			m = max(m, now);
			--i;
			if (st[top]) {
				son[now].insert(st[top]);
				son[st[top]].insert(now);
			}
			st[++top] = now;
		} else if (s[i] == ')') --top;
	}
	/*
	for(int i = 1; i <= m; ++i) {
		for(set<int>::iterator j = son[i].begin(); j != son[i].end(); ++j)
			printf("%d ", *j);
		puts("");
	}
	*/
	for(int i = 1; i <= m; ++i) {
		du[i] = son[i].size();
		if (son[i].size() == 1) Q.push(i);
	}
	while(!Q.empty()) {
		int x = Q.top(), y = 0; Q.pop();
		if (son[x].size()) y = *son[x].begin();
		if (son[x].size()) printf("%d ", y);
		--du[y];
		son[y].erase(x);
		if (du[y] == 1) Q.push(y);
	}
	puts("");
	return 0;
}
