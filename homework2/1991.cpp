#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
const int N = 100010;

int n, k;
double x[N];
bool check(double r) {
	int now = 1, num = 1;
	for(int i = 2; i <= n; ++ i) {
		if (x[i] - x[now] > 2 * r) {
			now = i;
			num ++;
//			printf("now = %d\n", now);
		}
	}
//	printf("r = %f num = %d\n", r, num);
	return num <= k;
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%lf", &x[i]);
	double l = 0.0, r = 2e7, mid, ans;
	while(r - l > eps) {
		mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid;
		else l = mid;
	}
	printf("%.6f\n", ans);
	return 0;
}
