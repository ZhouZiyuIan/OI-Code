#include <bits/stdc++.h>
using namespace std;
int x, y, xx, yy, h, w;
char a[1005][1005];
int vis[1005][1005];

struct node {
	int x, y, z;
	node(int aa = 0, int bb = 0, int cc = 0) {
		x = aa;
		y = bb;
		z = cc;
	}
	friend bool operator<(node l, node r) {
		return l.z > r.z;
	}
};

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void bfs() {
	priority_queue<node>q;
	q.push(node(x, y, 0));
	vis[x][y] = 0;
	while (!q.empty()) {
		int nx = q.top().x, ny = q.top().y, z = q.top().z;
        q.pop();
		for (int i = 0; i < 4; i++) {
			int sx = nx + dx[i], sy = ny + dy[i];
			int sxx = sx + dx[i], syy = sy + dy[i];
            printf("%d %d %d %d\n", sx, sy, sxx, syy);
			if (1 <= sx && sx <= h && 1 <= sy && sy <= w) {
				if (a[sx][sy] == '#') {
					if (vis[sx][sy] > z + 1 || vis[sx][sy] == -1)
						q.push(node(sx, sy, z + 1)), vis[sx][sy] = z + 1;
				} else if (vis[sx][sy] > z || vis[sx][sy] == -1)
					q.push(node(sx, sy, z)), vis[sx][sy] = z;

			}
			if (1 <= sxx && sxx <= h && 1 <= syy && syy <= w) {
				if ((a[sx][sy] == '#' || a[sxx][syy] == '#')) {
					if (vis[sxx][syy] > z + 1 || vis[sxx][syy] == -1)
						q.push(node(sxx, syy, z + 1)), vis[sxx][syy] = z + 1;
				} else if (vis[sxx][syy] > z || vis[sxx][syy] == -1)
					q.push(node(sxx, syy, z)), vis[sxx][syy] = z;
			}
		}
	}
	cout << vis[xx][yy];
}

signed main() {
	memset(vis, -1, sizeof(vis));
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> a[i][j];
	cin >> x >> y >> xx >> yy;
	bfs();
}