#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
typedef long long LL;

int n, k;
LL a[N];
set<LL>s;
set<LL> :: iterator it;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &a[i]);
		s.insert(a[i]);
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = n; i; -- i) {
		if ((it = s.find(a[i])) != s.end()) {
			ans ++;
			s.erase(it);
			if (a[i] % k == 0) {
				if ((it = s.find(a[i] / k)) != s.end())
					s.erase(it);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
