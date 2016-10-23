#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
const int dx[] = {1, 0, 0, -1},
	  	  dy[] = {0, 1, -1, 0};

int mp[N][N], d[N][N], n, ex, ey;

queue<pair<int,int> >Q;
int main() {
	memset(d, -1, sizeof d);
	scanf("%d%d%d", &ex, &ey, &n);
	ex += 500; ey += 500;
	for(int i = 1; i <= n; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x += 500; y += 500;
		mp[x][y] = -1;
	}
	Q.push(make_pair(500, 500));
	d[500][500] = 0;
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for(int i = 0; i < 4; ++ i) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx > 1000 || ty < 0 || ty > 1000 || mp[tx][ty]) continue;
			if (d[tx][ty] != -1) continue;
			if (tx == ex && ty == ey) {
				printf("%d\n", d[x][y] + 1);
				return 0;
			}
			d[tx][ty] = d[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
	}
	return 0;
}
