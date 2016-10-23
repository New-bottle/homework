#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
typedef long long LL;

int n, a[N], b[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	LL ans = 0;
	for(int i = 1; i <= n; i ++) ans += (LL) a[i] * b[i];
	printf("%lld ", ans);
	ans = 0;
	for(int i = 1; i <= n; i ++) ans += (LL) a[i] * b[n - i + 1];
	printf("%lld\n", ans);
	return 0;
}
