#include<bits/stdc++.h>
using namespace std;
int n, y, ans, a[1000005], cnt[1000005], len;
int main() {
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	cin >> n >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			cnt[++len] = a[i] - a[j];
	sort(cnt + 1, cnt + len + 1);
	for (int i = 1; i <= len; i++) if (cnt[i] != cnt[i - 1]) ans++;
	cout << ans;
}
