#include<bits/stdc++.h>
#define endl '\n'
#define int64 long long
using namespace std;
const int N = 1e3 + 5;
int n, y;
int x[N];
map<int64, int64> mp;
int64 ans;
signed main() {
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> y;
	for (int i = 1; i <= n; i++) cin >> x[i];
	sort(x + 1, x + 1 + n);//∑¿÷π‘ΩΩÁ 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!mp[x[j] - x[i]]) {
				mp[x[j] - x[i]] = 1;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
