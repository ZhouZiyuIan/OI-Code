#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
template<typename T>
void write(T x) {
	if(x < 0) {
		x = -x;
		putchar_unlocked(45);
	}
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}
int n, a[500001][6], k, id, b[500001], cnt0;
long long ans, prod = 1;
vector<int> s;
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cnt0 = n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 6; ++j) {
			cin >> a[i][j];
			s.emplace_back(a[i][j]);
		}
	}
	stable_sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	k = s.size();
	vector<vector<int>> upd(k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 6; ++j) {
			id = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
			upd[id].emplace_back(i);
		}
	}
	for(int i = 0; i < k - 1; ++i) {
		for(int j : upd[i]) {
			if(!b[j])--cnt0;
			else prod /= b[j];
			prod %= 998244353;
			++b[j];
			prod *= b[j];
			prod %= 998244353;
		}
		ans -= (cnt0 ? 0 : prod) * (s[i + 1] - s[i]);
		ans += 998244353;
		ans %= 998244353;
	}
	for(int i=0;i<n;++i){
		ans*=166374059;
		ans%=998244353;
	}
	ans += s[k - 1];
	write(ans);
}
