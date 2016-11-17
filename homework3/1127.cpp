#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;

char s[N];
int ok[N][N];
bool judge(int l, int r) 
{
	if (ok[l][r] != -1) return ok[l][r];
	if (l == r) return ok[l][r] = 1;
	
	if (s[l] == '{' && s[r] == '}')
		if (r == l + 1 || judge(l + 1, r - 1)) return ok[l][r] = 1;
	for(int i = l; i <= r; ++i) {
		if (s[i] == ',') {
			if (judge(l, i - 1) && judge(i + 1, r)) return ok[l][r] = 1;
			if (s[l] == '{' && s[r] == '}' && judge(l + 1, i - 1) && judge(i + 1, r - 1)) return ok[l][r] = 1;
		}
	}
	return ok[l][r] = 0;
}

int main() 
{
	int T, cs = 0;
	scanf("%d", &T);
	gets(s);
	while(T --) {
		printf("Word #%d: ", ++ cs);
		gets(s);
		int n = strlen(s);
		memset(ok, -1, sizeof ok);
		if (judge(0, n - 1)) puts("Set");
		else puts("No Set");
	}
	return 0;
}
