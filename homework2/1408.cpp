#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N  = 300010;

struct edge {
	int x, y, v;
	bool operator < (const edge &b) const {
		return v < b.v || (v == b.v && x < b.x);
	}
	void read() {
		scanf("%d%d%d", &x, &y, &v);
	}
}e[N];

int n, m, a[N][2], v[N][2], ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i)
		e[i].read();
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i ++) {
		int x = e[i].x, y = e[i].y;
		if (e[i].v == v[x][0]) {
			if (a[x][1] + 1 > a[y][0]) {
				if (e[i].v != v[y][0]) {
					a[y][1] = a[y][0];
					v[y][1] = v[y][0];
				}
				a[y][0] = a[x][1] + 1;
				v[y][0] = e[i].v;
			} else if (a[x][1] + 1 > a[y][1] && e[i].v != v[y][0]) {
				a[y][1] = a[x][1] + 1;
				v[y][1] = e[i].v;
			}
		} else {
			if (a[x][0] + 1 > a[y][0]) {
				if (e[i].v != v[y][0]) {
					a[y][1] = a[y][0];
					v[y][1] = v[y][0];
				}
				a[y][0] = a[x][0] + 1;
				v[y][0] = e[i].v;
			} else if (a[x][0] + 1 > a[y][1] && e[i].v != v[y][0]) {
				a[y][1] = a[x][0] + 1;
				v[y][1] = e[i].v;
			}
		}
		ans = max(ans, a[y][0]);
	}
	printf("%d\n", ans);
	return 0;
}
