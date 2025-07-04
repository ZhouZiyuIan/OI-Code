// Problem: E - Pair Annihilation
// Contest: AtCoder - AtCoder Beginner Contest 409
// URL: https://atcoder.jp/contests/abc409/tasks/abc409_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
pair<long long, pair<long long, long long> > cur;
stack<pair<long long, pair<long long, long long> > > st;
vector<pair<long long, long long> > edg[100001];
long long n, x[100001], u, v, w, ans, p, t;
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(long long i = 0; i < n; i++) {
		cin >> x[i];
	}
	for(long long i = 1; i < n; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		edg[u].emplace_back(v, w);
		edg[v].emplace_back(u, w);
	}
	st.push(make_pair(0, make_pair(-1, 0)));
	while(st.size()) {
		cur = st.top();
		st.pop();
		v = cur.first;
		p = cur.second.first;
		t = cur.second.second;
//		cout << cur.first << ' ' << cur.second.first << ' ' << cur.second.second << endl; 
		if(t == 0) {
			st.push(make_pair(v, make_pair(p, 1)));
			for(auto e : edg[cur.first]) {
				u = e.first;
				w = e.second;
				if(u != p) {
					st.push(make_pair(u, make_pair(v, 0)));
				}
			}
		}
		else {
			for(auto e : edg[cur.first]) {
				u = e.first;
				w = e.second;
				if(u == p) {
					continue;
				}
				ans += w * abs(x[u]);
				x[v] += x[u];
			}
		}
	}
	cout << ans;
}
