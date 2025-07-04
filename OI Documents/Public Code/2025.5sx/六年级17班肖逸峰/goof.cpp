#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int k, cnt[30][3], ans = 26;
int main() {
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout);
	scanf("%s", s);
	cin >> k;
	int len = strlen(s);
	for (int i = 0; i <= len; i++) {
		cnt[s[i] - 'a' + 1][1]++;
		cnt[s[i] - 'a' + 1][2] = s[i] - 'a' + 1;
	}
	for (int i = 1; i <= 26; i++)
		for (int j = 1; j <= 26; j++)
			if (cnt[i][1] < cnt[j][1]) {
				swap(cnt[i][1], cnt[j][1]);
				swap(cnt[i][2], cnt[j][2]);
			}
	for (int i = 1; i <= 26; i++) {
		if (k - cnt[i][1] >= 0 && cnt[i][2] != 0) {
			k -= cnt[i][1];
			for (int j = 0; j < len; j++) if (s[j] == cnt[i][2] + 'a' - 1) s[j] = '-';
			cnt[i][2] = 0;
		}
	}
	for (int i = 1; i <= 26; i++) if (cnt[i][2] == 0) ans--;
	cout << ans << endl;
	for (int i = 0; i < len; i++) if (s[i] != '-') cout << s[i];
}
