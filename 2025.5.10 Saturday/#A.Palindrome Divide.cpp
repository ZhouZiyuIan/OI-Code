#pragma GCC optimize("Ofast")
#include <iostream>
using namespace std;
const int MOD = 998244353;
int T, ls, le, rs, re, cnt;
long long hsh, hst, baset;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> s;
		hsh = hst = cnt = ls = le = 0;
		baset = 1;
		rs = re = s.size() - 1;
		while(le <= rs) {
			hsh = (hsh * 131 + s[le]) % MOD;
			hst = (hst + s[rs] * baset) % MOD;
			baset *= 131;
			baset %= MOD;
			while(hsh != hst) {
				le++;
				rs--;
				hsh = (hsh * 131 + s[le]) % MOD;
				hst = (hst + s[rs] * baset) % MOD;
				baset *= 131;
				baset %= MOD;
			}
			le = ls = le + 1;
			rs = re = rs - 1;
			cnt += 2;
			hsh = hst = 0;
			baset = 1;
		}
		cout << cnt - (rs + 2 <= le ? 1 : 0) << endl;
	}
}
