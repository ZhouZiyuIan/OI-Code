#include<bits/stdc++.h>
#define endl '\n'
#define int64 long long
using namespace std;
const int N = 1e5 + 5;
int n;
int64 t;
int64 a[N];
int64 tot;
signed main() {
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];	
	}
	t %= tot;
	for (int i = 1; i <= n; i++) {
		if (t - a[i] <= 0) {
			cout << i << endl <<  a[i] - t;
			break;
		}
		t -= a[i];
	}
	return 0;
}
