#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1000100;

bool vis[N];

int prime[N], cnt, n, ans[N];
int main() {
	for(int i = 2; i <= 1000000; i ++)
		if (!vis[i]) {
			prime[++ cnt] = i;
			for(LL j = (LL)i * i; j <= 1000000; j += i)
				vis[j] = 1;
		}
	scanf("%d", &n);
	int m = n;
	for(int i = 1; i <= cnt; i ++) {
		while(n % prime[i] == 0) {
			n /= prime[i];
			ans[i] ++;
		}
	}
	printf("%d=", m);
	for(int i = 1; i <= cnt; i ++)
		if (ans[i]) printf("%d(%d)", prime[i], ans[i]);
	if (n != 1) printf("%d(1)\n", n);
	return 0;
}
