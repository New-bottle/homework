#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int dx[] = {1, 0, 0, -1},
	  	  dy[] = {0, 1, -1, 0};
const int N = 110;

int a[N][N];
bool v[N][N];
int main() {
	int n, num = 0, m = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) v[i][j] = 1;
			if (a[i][j] == 0) num ++;
		}
	for(int times = 1; times <= 10000; times ++) {
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if (!v[i][j] && a[i][j] != 2)
					for(int k = 0; k < 4; k ++) {
						int x = i + dx[k], y = j + dy[k];
						if (x < 1 || x > n || y < 1 || y > n) continue;
						if (a[x][y] == 1) {
							v[i][j] = 1;
							m ++;
							break;
						}
					}
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) if (a[i][j] == 0 && v[i][j] == 1) a[i][j] = 1;
		/*
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++)
				printf("%d ", v[i][j]);
			puts("");
		}
		*/
		if (num == m) {
			printf("%d\n", times);
			break;
		}
	}
	return 0;
}
