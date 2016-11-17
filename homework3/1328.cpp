#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int T;
	scanf("%d", &T);
	int mx, d;
	while(T --) {
		scanf("%d", &n);
		scanf("%d", &d);
		mx = d;
		for(int i = 2; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			mx = max(mx, x);
			d = gcd(d, x);
		}
		mx /= d;
		puts((mx - n) & 1 ? "Alice" : "Bob");
	}
	return 0;
}
