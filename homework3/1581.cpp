#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int l, n, m, a[N];

bool check(int len) {
	int last = 0, num = 0;
	for(int i = 1; i <= n; ++i) {
		if (a[i] - a[last] < len) {
			num ++;
		} else {
			last = i;
		}
	}
	if (a[n + 1] - a[last] < len) ++num;
	return num <= m;
}
int main() {
	scanf("%d%d%d", &l, &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	a[0] = 0; a[n + 1] = l;

	int L = 1, R = l, mid, ans = 1;
	while(L <= R) {
		mid = (L + R) >> 1;
		if (check(mid)) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
