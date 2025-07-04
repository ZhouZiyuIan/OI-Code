#include<bits/stdc++.h>
#define endl '\n'
#define int64 long long
using namespace std;
int k;
int ans;
struct Node {
	int s;
	char ch;	
} cnt[1005];

string s; 

bool cmp(Node x, Node y) {
	return x.s < y.s;
}

signed main() {
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	cin >> k;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (cnt[s[i] - 'a' + 1].s == 0) ans++;
		cnt[s[i] - 'a' + 1].s++;
		cnt[s[i] - 'a' + 1].ch = s[i];
	}
	sort(cnt + 1, cnt + 1 + 26, cmp);
	for (int i = 1; i <= 26; i++) {
		if(!cnt[i].s) continue;
		if (k - cnt[i].s < 0) {
			cout << ans << endl;
			for (int j = 0; j < len; j++) {
				bool ok = true;
				for (int k = 1; k < i; k++) {
					if (s[j] == cnt[k].ch) {
						ok = false;
						break;
					}
				} 
				if (ok) cout << s[j]; 
			}
			return 0;
		}
		k -= cnt[i].s;
		ans--;
	}
	cout << 0 << endl;
	return 0;
}
