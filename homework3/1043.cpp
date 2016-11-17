#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000010;
int n, fa[N], size[N], son[N][2], dep[N];

#define L son[x][0]
#define R son[x][1]
bool solve(int x) {
	size[x] = dep[x] = 1;
	if (!L) return (!R);
	if (solve(L)) {
		size[x] += size[L];
		dep[x] = max(dep[x], dep[L] + 1);
	} else return false;
	if (R) {
		if (solve(R)) {
			dep[x] = max(dep[x], dep[R] + 1);
			size[x] += size[R];
		} else return false;
	}

	if (size[L] < size[R]) return false;
	if (dep[L] - dep[R] > 1 || dep[L] - dep[R] < 0) return false;
	if (dep[L] - dep[R] == 0) {
		if (size[L] != (1 << dep[L]) - 1) return false;
	} else {
		if (size[R] != (1 << dep[R]) - 1) return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d", &fa[i]);
		if (son[fa[i]][0] == 0) son[fa[i]][0] = i;
		else if (son[fa[i]][1] == 0) son[fa[i]][1] = i;
		else {
			puts("false");
			return 0;
		}
	}
	for(int x = 0; x < n; ++x) {
		if (!L) L = n;
		if (!R) R = n;
	}
//	for(int x = 0; x < n; ++x) printf("%d %d\n", L, R);
	puts(solve(0) ? "true" : "false");
//	for(int i = 0; i < n; ++i) printf("solve(%d) = %d\n", i, solve(i));
	return 0;
}
