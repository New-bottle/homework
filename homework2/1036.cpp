#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
typedef long long LL;

int n, a[N];

void solve1() {
	LL w = 0, t = 0;
	LL s1 = 0, s2 = 0, s0 = 0;
	for(int i = 1; i <= n; i ++) {
		if (i % 3 == 1) {
			w += s1;
			s1 += a[i];
		} else if (i % 3 == 2) {
			w += s2;
			s2 += a[i];
		} else {
			w += s0;
			s0 += a[i];
		}
	}
	t = max(s1, max(s2, s0));
	printf("%lld %lld\n", w, t);
}
void solve2() {
	LL w = 0, t = 0;
	LL t1 = 0, t2 = 0, t3 = 0;
	for(int i = 1; i <= n; i ++) {
		if (t1 == 0) {
			t1 = a[i];
		} else if (t2 == 0) {
			t2 = a[i];
		} else t3 = a[i];
		LL mn = min(t1, min(t2, t3));
		w += (n - i) * mn;
		t += mn;
		t1 -= mn; t2 -= mn; t3 -= mn;
	}
	if (t1 || t2 || t3) {
		t += max(t1, max(t2, t3));
	}
	printf("%lld %lld\n", w, t);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	solve1();
	solve2();
	return 0;
}
