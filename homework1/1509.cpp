#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int st[3000];
bool run[3000];//pinyin
int days[3000][15];

int main() {
	int a, b, c, y1, y2;
	scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
	c %= 7;
	int nowy = 1850;
	st[1850] = 2;
	run[1850] = 0;
	for(nowy = 1851; nowy <= y2; nowy ++) {
		int tmp = 0;
		if (run[nowy - 1]) tmp = 366;
		else tmp = 365;
		st[nowy] = (st[nowy - 1] + tmp) % 7;
		run[nowy] = ((nowy % 4 == 0) && (nowy % 100 != 0)) || (nowy % 400 == 0);
		int *t = days[nowy];
		t[1] = t[3] = t[5] = t[7] = t[8] = t[10] = t[12] = 31;
		t[4] = t[6] = t[9] = t[11] = 30;
		t[2] = run[nowy] ? 29 : 28;
	}
	for(int nowy = y1; nowy <= y2; nowy ++) {
		int tmp = st[nowy];
		for(int i = 1; i < a; i ++) tmp = (tmp + days[nowy][i]) % 7;

		int cnt = (tmp == c);
		if (cnt == b) {
			int now = 1;
			printf("%d/%02d/%02d\n", nowy, a, now);
			continue;
		}
		bool sign = 0;
		for(int now = 2;cnt < b && now <= days[nowy][a]; now ++) {
			tmp = (tmp + 1) % 7;
			if (tmp == c) cnt ++;
			if (cnt == b) {
				sign = 1;
				printf("%d/%02d/%02d\n", nowy, a, now);
				break;
			}
		}
		if (!sign) puts("none");
	}			

	return 0;
}
