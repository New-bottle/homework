#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;

char s[N];
int isset[N][N], iselement[N][N], islist[N][N];

bool checklist(int l, int r);
bool checkset(int l, int r) {
	if (isset[l][r] != -1) return isset[l][r];
	int &f = isset[l][r];
	if (s[l] == '{' && s[r] == '}' && checklist(l + 1, r - 1)) return f = 1;
	return f = 0;
}
bool checkelement(int l, int r) {
	if (iselement[l][r] != -1) return iselement[l][r];
	int &f = iselement[l][r];
	if (l == r) return f = 1;
	if (checkset(l, r)) return f = 1;
	return f = 0;
}
bool checklist(int l, int r) {
	if (islist[l][r] != -1) return islist[l][r];
	int &f = islist[l][r];
	if (l == r + 1) return f = 1;
	if (checkelement(l, r)) return f = 1;
	for(int i = l + 1; i < r; ++i) {
		if (s[i] == ',') {
			if (checkelement(l, i - 1) && checklist(i + 1, r)) return f = 1;
		}
	}
	return f = 0;
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
		memset(isset, -1, sizeof isset);
		memset(iselement, -1, sizeof iselement);
		memset(islist, -1, sizeof islist);
		if (checkset(0, n - 1)) puts("Set");
		else puts("No Set");
	}
	return 0;
}
