#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e18;
int T;
int n;
int s, l[N], r[N];

bool check(int x) {
	int se = 0, L = 0, R = 0; 
	int res = x;
	for (int i = 1; i <= n; i++) {
		if (l[i] <= x && r[i] >= x) se++;
		else if (l[i] <= x) L++, res += l[i];
		else if (r[i] >= x) R++, res += x;
		if (res > s) return false;
	}
	if (L < n / 2) se -= n / 2 - L, res += (n / 2 - L) * x;
	if (R < n / 2) se -= n / 2 - R, res += (n / 2 - R) * x;
	if (res > s) return false;
	if (se == 1) return true;
	return false;
}

signed main() {	
	freopen("payday.in", "r", stdin);
	freopen("payday.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> s;
		int L = inf, R = 0;
		for (int i = 1; i <= n; i++) {
			cin >> l[i] >> r[i];
			L = min(l[i], L);
			R = max(r[i], R);
		}
		for (int i = min(s, R); i >= L; i--) {
			if(check(i)) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
