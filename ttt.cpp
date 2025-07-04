#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> edg[40001];
int n, p, ans, a[40001], fm[40001], fn[40001], gm[40001], gn[40001];
char lab[40001][1];
void dfs(int u) {
	for(auto v : edg[u]) {
		dfs(v);
		fm[u] = max(fm[u], fm[v]);
		fn[u] = min(fn[u], fn[v]);
	}
	fm[u] += a[u];
	fn[u] += a[u];
}
void sol(int u) {
	gm[u] += a[u];
	gn[u] += a[u];
	for(auto v : edg[u]) {
		gm[v] = max(a[u], gm[u]);
		gn[v] = min(a[u], gn[u]);
	}
	if(edg[u].size() > 1) {
		int mx = 0, mt = 0, mn = 0, mp = 0;
		for(auto v : edg[u]) {
			if(fm[v] > mx) {
				mt = mx;
				mx = fm[v];
			}
			else mt = max(mt, fm[v]);
			if(fn[v] < mn) {
				mp = mn;
				mn = fn[v];
			}
			else mp = min(mp, fn[v]);
		}
		for(auto v : edg[u]) {
			gm[v] = max(gm[v], (fm[v] == mx ? mt : mx) + a[u]);
			gn[v] = min(gn[v], (fn[v] == mn ? mp : mn) + a[u]);
		}
	}
	for(auto v : edg[u]) {
		sol(v);
	}
}
int main() {
//	freopen("btree.in", "r", stdin);
//	freopen("btree.out", "w", stdout);
//	ios :: sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		cin >> p;
		edg[p].emplace_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		cin >> lab[i];
		a[i] = (lab[i][0] == '(' ? 1 : -1);
	}
	dfs(1);
	sol(1);
	for(int i = 2; i <= n; ++i) {
		ans = max(max(ans, min(fm[i], a[i] - gn[i])), min(-fn[i], gm[i] - a[i]));
	}
	cout << ans;
}
