#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int ans[15], a[15];
int main() {
	int saved = 0, now = 0, ans = 0;
	for(int i = 1; i <= 12; i ++) {
		scanf("%d", &a[i]);
		if (ans) continue;
		if (now + 300 < a[i]) {
			ans = i;
			continue;
		} else {
			now = now + 300 - a[i];
			saved += now - now % 100;
			now %= 100;
		}
//		printf("saved = %d now = %d\n", saved, now);
	}
	if (ans) printf("-%d\n", ans);
	else {
		printf("%d\n", now + int(saved * 1.2));
	}
	return 0;
}
