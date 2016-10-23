#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
const int dx[] = {1, 0, 0, -1},
	  	  dy[] = {0, 1, -1, 0};

int n, m, dist[10][10], d[10][N][N], mp[N][N], stx, sty;
typedef pair<int,int> pii;
vector<pii > p;

void bfs(int sx, int sy, int d[N][N]) {
//	printf("%d %d\n", sx, sy);
	queue<pii >Q;
//	memset(d, -1, sizeof d);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j) d[i][j] = -1;
	Q.push(make_pair(sx, sy));
	d[sx][sy] = 0;
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for(int i = 0; i < 4; ++ i) {
			int tx = x + dx[i], ty = y + dy[i];
			if (mp[tx][ty] == -1 || tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (d[tx][ty] != -1) continue;
			d[tx][ty] = d[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
	}
	/*
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) printf("%d ", d[i][j]); puts(""); 
	}
	*/
}

bool used[10];
int ans = 1e9, a[10];
long long tmp;
void dfs(int x) {
//	printf("x = %d tmp = %lld\n", x, tmp);
//	for(int i = 1; i <= p.size() + 1; ++ i) printf("%d ", a[i]); puts("");
	if (x == p.size() + 2) {
		ans = min((long long)ans, tmp);
		return;
	}
	for(int i = 2; i <= p.size() + 1; ++ i) {
		if (!used[i]) {
			used[i] = 1;
			a[x] = i;
			tmp = tmp + dist[a[x - 1]][i];
			dfs(x + 1);
			tmp -= dist[a[x - 1]][i];
			a[x] = 0;
			used[i] = 0;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j) {
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 2) stx = i, sty = j;
			if (mp[i][j] == 1) p.push_back(make_pair(i, j));
		}
	bfs(stx, sty, d[1]);
	for(int j = 0; j < p.size(); ++ j)
		dist[1][j + 2] = d[1][p[j].first][p[j].second];
	for(int i = 0; i < p.size(); ++ i) {
		bfs(p[i].first, p[i].second, d[i + 2]);
		for(int j = 0; j < p.size(); ++ j)
			dist[i + 2][j + 2] = d[i + 2][p[j].first][p[j].second];
	}
	for(int i = 1; i <= p.size() + 1; ++ i)
		for(int j = 1; j <= p.size() + 1; ++ j) if (dist[i][j] == -1) dist[i][j] = 1e9;
	a[1] = 1;
	dfs(2);
	if (ans == 1000000000) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
