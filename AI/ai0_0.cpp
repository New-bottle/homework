#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int TOTALNUM = 25;
const int TOTALKIND = 12;
const int UPPER_RANGE_L = 11, UPPER_RANGE_R = 16;
const int LOWER_RANGE_L = 0, LOWER_RANGE_R = 5;
const int H = 17;
const int W = 5;
const int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int rounds = 0;
int id;
int map[H][W];

int value[H][W];
const int weight[TOTALKIND];

deque<int>tmp[H][W];

namespace already{
bool exist(int x, int y) {
    return (LOWER_RANGE_L <= x && x <= LOWER_RANGE_R && 0 <= y && y < W)
		|| (UPPER_RANGE_L <= x && x <= UPPER_RANGE_R && 0 <= y && y < W)
		|| ((x == 6 || x == 8 || x == 10) && (y == 0 || y == 2 || y == 4));
}
void change() {
    int x, y, xx, yy, col, kind;
    cin >> x >> y >> xx >> yy >> col >> kind;
	cerr << "Get updates:"  << endl;
	cerr << x << ' ' << y << ' ' << xx << ' ' << yy << ' ' << col << ' ' << kind << endl;
    int tar = col * TOTALKIND + kind;
    if (x == xx && y == yy) map[x][y] = tar;
    else {
        map[x][y] = -2;
        map[xx][yy] = tar;
    }
}
//0 1 for 1
//2 3 4 5 10 for 2
//6 7 8 9 for 3
void show_init(int id)
{
//	/*
	int opt[25] = { 9, 11,  3, 7, 4,
				    7,  9,  9, 8, 8,
					10,     5,   10,
					6,  2,     7, 6,
					3,      5,    2, 
					0,  8,  1, 4, 6};
//					*/
	//give a initializing map here
	//this line : kind1 kind2 ... etc
	//Imagine that the chesses are listed from the bottom to the top, left to right
	//This is a stupid start:
//	int opt[25] = {10, 11, 10, 2, 2, 9, 9, 9, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 1, 0, 3, 3};
	for (int i = 0; i < 25; ++i)
		cout << opt[i] << ' ';
	cout << endl;
}
void get_init()
{
	int arr0[25], arr1[25];
	for (int i = 0; i < 25; ++i)
	{
		cin >> arr0[i];
	}
	for (int i = 0; i < 25; ++i)
	{
		cin >> arr1[i];
		arr1[i] += TOTALKIND;
	}
	map[0][0] = arr0[0];
	map[0][1] = arr0[1];
	map[0][2] = arr0[2];
	map[0][3] = arr0[3];
	map[0][4] = arr0[4];
	map[1][0] = arr0[5];
	map[1][1] = arr0[6];
	map[1][2] = arr0[7];
	map[1][3] = arr0[8];
	map[1][4] = arr0[9];
	map[2][0] = arr0[10];
	map[2][2] = arr0[11];
	map[2][4] = arr0[12];
	map[3][0] = arr0[13];
	map[3][1] = arr0[14];
	map[3][3] = arr0[15];
	map[3][4] = arr0[16];
	map[4][0] = arr0[17];
	map[4][2] = arr0[18];
	map[4][4] = arr0[19];
	map[5][0] = arr0[20];
	map[5][1] = arr0[21];
	map[5][2] = arr0[22];
	map[5][3] = arr0[23];
	map[5][4] = arr0[24];
	map[16][0] = arr1[4];
	map[16][1] = arr1[3];
	map[16][2] = arr1[2];
	map[16][3] = arr1[1];
	map[16][4] = arr1[0];
	map[15][0] = arr1[9];
	map[15][1] = arr1[8];
	map[15][2] = arr1[7];
	map[15][3] = arr1[6];
	map[15][4] = arr1[5];
	map[14][0] = arr1[12];
	map[14][2] = arr1[11];
	map[14][4] = arr1[10];
	map[13][0] = arr1[16];
	map[13][1] = arr1[15];
	map[13][3] = arr1[14];
	map[13][4] = arr1[13];
	map[12][0] = arr1[19];
	map[12][2] = arr1[18];
	map[12][4] = arr1[17];
	map[11][0] = arr1[24];
	map[11][1] = arr1[23];
	map[11][2] = arr1[22];
	map[11][3] = arr1[21];
	map[11][4] = arr1[20];

	//fixme
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j) tmp[i][j].clear(), tmp[i][j].push_back(map[i][j]);
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j) value
			//set the maps' value (position)
}
}
using namespace already;

namespace ontrack{
bool ontrack[H][W];
inline bool camp(int xx, int yy) {
	if ((xx == 2 || xx == 4 || xx == 12 || xx == 14) && (yy == 1 || yy == 3)) return 1;
	if ((xx == 3 || xx == 13) && (yy == 2)) return 1;
	return 0;
}
void init() {
	for(int i = 0; i < 5; ++ i)
		ontrack[1][i] = ontrack[5][i] = ontrack[11][i] = ontrack[15][i] = 
		ontrack[6][i] = ontrack[8][i] = ontrack[10][i] = 1;
	for(int j = 1; j < 16; ++ j)
		ontrack[j][0] = ontrack[j][4] = 1;
	for(int i = 7; i <= 9; i += 2)
		for(int j = 0; j <= 4; j += 2)
			ontrack[i][j] = 1;
	for(int i = 0; i < H; ++ i) {
		for(int j = 0; j < W; ++ j) printf("%d ", ontrack[i][j]); puts("");
	}
}

bool checktrack(int sx, int sy, int tx, int ty) {
	static queue<pii >Q;
	static bool vis[H][W];
	Q.push(make_pair(sx, sy));
	memset(vis, 0, sizeof vis);
	vis[sx][sy] = 1;
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for(int i = 0; i < 4; i ++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!ontrack[xx][yy] || vis[xx][yy]) continue;
			if (xx == tx && yy == ty) {
				while(!Q.empty()) Q.pop();
				return 1;
			}
			Q.push(make_pair(xx, yy));
			vis[xx][yy] = 1;
		}
	}
	return 0;
}
}
using namespace ontrack;
inline int col(int x, int y) {
	return map[x][y] / TOTALKIND;
}

bool can(int x, int y, int xx, int yy) {
	if (col(x, y) == col(xx, yy) || !exist(xx, yy)) return 0;
	if (exist(xx, yy)) {
		if (camp(x, y)) {
			for(int i = 0; i < 8; ++ i) {
				int tx = x + dx[i], ty = y + dy[i];
				if (tx == xx && ty == yy && col(x, y) != col(tx, ty)) return 1;
			}
		} else {
			for(int i = 0; i < 4; ++ i) {
				int tx = x + dx[i], ty = y + dy[i];
			}
		}
	}
	return 0;
}
bool legal(int kind, int x, int y, int tox, int toy) {
	if (kind == 9) {
		if (ontrack[x][y] && ontrack[tox][toy] && checktrack(x, y, tox, toy))
		//if (x, y) can goto (tox, toy) and there no other dice between them
			return 1;
		if (can(x, y, tox, toy)) return 1;
		//if can directly reach (tox, toy) from (x, y)
		return 0;
	}
	return 
}

LL getval(int id) {
	LL ans = 0;
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j) {
			int sign = 0;
			if (map[i][j] / TOTALKIND == id) sign = 1;
			else sign = -1;
			ans = ans + value[i][j] * weight[map[i][j] % TOTALKIND];
		}
	return ans;
}

struct method {
	int posx, posy, tox, toy;
};

LL dfs(int x, int y, int xx, int yy, int id, int dep) {
	if (dep > dep_limit) return getval(id);
	//fixme
}
method find_best() {
	method ans;
	LL max = -1e18;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (dfs(i, j, ii, jj, id, 0) > max) ans = (mathod){i, j, ii, jj};
	return ans;
}

void make_decision(int &x, int &y, int &xx, int &yy) {
	//fixme
	method ans = find_best();
	x = ans.x; y = ans.y; xx = ans.xx; yy = ans.yy;
	return;
	/*
	for(int x = 0; x < H; ++ x)
		for(int y = 0; y < W; ++ y) {
			if (!exist(x, y)) continue;
			if (map[x][y] == -2) continue;
			if (x == 0 && (y == 1 || y == 3)) continue;
			if (x == 16 && (y == 1 || y == 3)) continue;
			if (map[x][y] % TOTALKIND == 9) continue;
			if (map[x][y] % TOTALKIND == 11) continue;
			if (map[x][y] / TOTALKIND == id) {
				int tar = map[x][y] % TOTALKIND;
				if (
			}*/
	int n = 0;
    while (true) {
		++n;
        x = rand() % H;
        y = rand() % W;
		if (!exist(x, y)) continue;
        if (map[x][y] == -2) continue;
		if (x == 0 && (y == 1 || y == 3)) continue;
		if (x == 16 && (y == 1 || y == 3)) continue;
		if (map[x][y] % TOTALKIND == 9) continue;
		if (map[x][y] % TOTALKIND == 11) continue;
        if (map[x][y] / TOTALKIND == id) {
            int tar = map[x][y] % TOTALKIND;
            int d = rand() % 4;
            xx = x + dx[d];
            yy = y + dy[d];
			cerr << "Trying " << x << ", " << y << " to " << xx << ", " << yy << endl;
			if ((xx == 2 || xx == 4 || xx == 12 || xx == 14) && (yy == 1 || yy == 3)) continue;
			if ((xx == 3 || xx == 13) && (yy == 2)) continue;
			//in camp
            if (exist(xx, yy)) {
                if (map[xx][yy] == -2) {
                    return;
                } else {
                    if (map[xx][yy] / TOTALKIND == id) continue;
					return;
				}
            }
        }
	}
}

inline void end() {
    std::cout << "END\n" << std::flush;
}

int main(int argc, char** argv) {
    unsigned seed = time(0);
    if (argc == 2) {
        cerr << "Excited! Get given seed = " << argv[1] << endl;
        seed = 0;
        for (char *pc = argv[1]; *pc; ++pc)
            seed = seed * 10 + (*pc - '0');
    }
    srand(seed);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            map[i][j] = -2;
        }
    }
    string op;
    while (true) {
        cin >> op;
        if (op == "id") {
            cin >> id;
			cerr << id << endl;
            cout << "送分一号" << endl;
            end();
		} else if (op == "refresh") {
			get_init();
        } else if (op == "init") {
			show_init(id);
			end();
		} else if (op == "message") {
            change();
        } else if (op == "action") {
            int x, y, xx, yy;
            make_decision(x, y, xx, yy);
			cerr << x << " " << y << " " << xx << " " << yy << endl;
            cout << x << " " << y << " " << xx << " " << yy << endl;
            end();
        }
    }
}

