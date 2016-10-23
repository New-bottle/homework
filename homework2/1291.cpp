#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
const int P = 1e9 + 7;
typedef long long LL;

int n;
LL c[N][N], f[N];

LL solve(int x) {
//	printf("solve %d\n", x);
	if (x <= 1) return 1;
	if (f[x]) return f[x];
	int t = 1;
	for(t = 1; x - t > (t << 1) - 1; t <<= 1);
//	printf("%d = %d + %d + 1\n", x, t - 1, x - t);
	f[x] = solve(t - 1) * solve(x - t) % P * c[x - 1][t - 1] % P;
	return f[x];
}

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 1) {
		puts("1");
		return 0;
	}
	for(int i = 0; i <= n; ++ i) c[i][0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= i; ++ j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
	printf("%lld\n", solve(n) * 2LL % P);
	return 0;
}
