#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N = 15;
const int M = 1e4 + 5;
int T;
int n, m;
char a[N][M];
int sx, sy;

struct Node {
	int x, y, t;
};

bool bfs() {
	queue<Node> q;
	q.push({sx, sy, 0});
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().t;
		cout << x << " " << y << " " << t << endl;
		q.pop();
		if (a[x][y + 1] == 'X') continue;
		if (t >= n - 1) return true;
		int ny = y + 1 + 2 * t;
		if (x >= 1 && x <= m && a[x][ny] != 'X') q.push({x, ny, t + 1});
		if (x + 1 >= 1 && x <= m && a[x + 1][ny] != 'X') q.push({x + 1, ny, t + 1});
		if (x - 1 >= 1 && x <= m && a[x - 1][ny] != 'X') q.push({x - 1, ny, t + 1});
	}
	return false;
}

signed main() {
	freopen("parkour.in", "r", stdin);
	freopen("parkour.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 's') sx = i, sy = j;
			}
		}
		if (bfs()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
