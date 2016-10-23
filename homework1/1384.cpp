#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000010;
const int P = 1e9 + 7;

int n, belong[N], f[N];
vector<int>have[5];

int main() {
	f[1] = 1;
	for(int i = 2; i <= 1000000; i ++) f[i] = (f[i - 1] * 2  + 1) % P;
	scanf("%d", &n);
	int now = 1, ans = -1, last = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &belong[i]);
		if (belong[i] == belong[i - 1]) now ++;
		else {
			ans = (ans + f[now]) % P;
			last = now;
			now = 1;
		}
	}
	if (belong[n] != 3) {
		ans = (ans + f[now]) % P;
		ans = (ans + f[n - now]) % P;
	}
	printf("%d\n", ans);
	return 0;
}
/*
   1   2   3

   3   2     
   5   4   1   
   */
