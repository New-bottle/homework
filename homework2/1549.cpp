#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;

char s[N];
bool cant[N];
int main() {
	while(scanf("%s", s + 1) != EOF) {
		puts(s + 1);
		int l = strlen(s + 1), now = 0;
		for(int i = 1; i <= l; i ++) {
			if (s[i] == '(') now ++;
			else if (s[i] == ')') {
				if (now) now --;
				else cant[i] = 1;
			}
		}
		now = 0;
		for(int i = l; i; i --) {
			if (s[i] == ')') now ++;
			else if (s[i] == '(') {
				if (now) now --;
				else cant[i] = 1;
			}
		}
		for(int i = 1; i <= l; i ++)
			if (cant[i]) {
				if (s[i] == ')') putchar('?');
				else putchar('$');
			} else putchar(' ');
		puts("");
	}
	return 0;
}
