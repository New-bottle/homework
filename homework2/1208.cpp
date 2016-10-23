#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double pi = acos(-1.0);

int main() {
	double a, b, ans = 0.0;
	while(cin >> a >> b) {
		ans = max(ans, acos(b / a) * a * a - b * sqrt(a * a - b * b));
	}
	printf("%.2f\n", ans);
	return 0;
}
