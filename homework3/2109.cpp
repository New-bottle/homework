#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100010;

int a[N], n, m;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int b, c;
		scanf("%d%d", &b, &c);
		int l = 1, r = n, mid, ans = 0;
		while(l <= r) {
			mid = (l + r) >> 1;
			if (a[mid] * c * 4LL <= (LL)b * b) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
