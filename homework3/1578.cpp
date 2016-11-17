#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1211;
int n, m, x, y;
char s[N][N];
struct node {
	int s1, s2, s3;
	node(int n1 = 0, int n2 = 0, int n3 = 0) : s1(n1), s2(n2), s3(n3) {}
	node operator + (const node &b) const {
		return node(s1 + b.s1, s2 + b.s2, s3 + b.s3);
	}
	node operator - (const node &b) const {
		return node(s1 - b.s1, s2 - b.s2, s3 - b.s3);
	}
	void print() {
		printf("%d %d %d\n", s1, s2, s3);
	}
} a[N][N], sm[N][N], tri[N][N][10];
int main() {
	scanf("%d%d", &n, &m);
	gets(s[0]);
	for(int i = 1; i <= n; ++i) {
		gets(s[i] + 1);
		for(int j = 1; j <= m; ++j) {
			if (s[i][j] == 'C') a[i][j].s1 = 1;
			else if (s[i][j] == 'D') a[i][j].s2 = 1;
			else if (s[i][j] == 'M') a[i][j].s3 = 1;
			else if (s[i][j] == 'H') x = i, y = j;
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			sm[i][j] = sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1] + a[i][j];
			tri[i][j][0] = tri[i - 1][j - 1][0] + sm[i][j] - sm[i - 1][j];
			tri[i][j][1] = tri[i - 1][j - 1][1] + sm[i][j] - sm[i][j - 1];
		}
	memset(sm, 0, sizeof sm);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j; --j) {
			sm[i][j] = sm[i - 1][j] + sm[i][j + 1] - sm[i - 1][j + 1] + a[i][j];
			tri[i][j][2] = tri[i - 1][j + 1][2] + sm[i][j] - sm[i][j + 1];
			tri[i][j][3] = tri[i - 1][j + 1][3] + sm[i][j] - sm[i - 1][j];
		}
	memset(sm, 0, sizeof sm);
	for(int i = n; i; --i)
		for(int j = 1; j <= m; ++j) {
			sm[i][j] = sm[i + 1][j] + sm[i][j - 1] - sm[i + 1][j - 1] + a[i][j];
			tri[i][j][6] = tri[i + 1][j - 1][6] + sm[i][j] - sm[i][j - 1];
			tri[i][j][7] = tri[i + 1][j - 1][7] + sm[i][j] - sm[i + 1][j];
		}
	memset(sm, 0, sizeof sm);
	for(int i = n; i; --i)
		for(int j = m; j; --j) {
			sm[i][j] = sm[i + 1][j] + sm[i][j + 1] - sm[i + 1][j + 1] + a[i][j];
			tri[i][j][4] = tri[i + 1][j + 1][4] + sm[i][j] - sm[i + 1][j];
			tri[i][j][5] = tri[i + 1][j + 1][5] + sm[i][j] - sm[i][j + 1];
		}
	int q;
	scanf("%d", &q);
	char opt[4];
	while(q --) {
		scanf("%s", opt);
		if (opt[0] == 'N') {
			if (x == 1) continue;
			x --;
			(tri[x][y][1] + tri[x - 1][y + 1][2]).print();
		} else if (opt[0] == 'S') {
			if (x == n) continue;
			x ++;
			(tri[x][y][5] + tri[x + 1][y - 1][6]).print();
		} else if (opt[0] == 'W') {
			if (y == 1) continue;
			y --;
			(tri[x][y][0] + tri[x + 1][y - 1][7]).print();
		} else if (opt[0] == 'E') {
			if (y == m) continue;
			y ++;
			(tri[x][y][4] + tri[x - 1][y + 1][3]).print();
		}
//		printf("q = %d %d %d\n", 11 - q, x, y);
	}
	return 0;
}
