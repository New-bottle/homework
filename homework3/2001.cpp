#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int a[N], s[N], n, m;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", s[y] - s[x - 1]);
	}
	return 0;
}
