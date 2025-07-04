#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
int T, h, w, v, x[400001], s[400001], cnt[800001];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> h >> w;
		vector<string>t(h);
		for(int i = 0; i < h; ++i) {
			cin >> t[i];
		}
		if(h > w){
			swap(h, w);
			vector<string>s(h, string(w, '.')); 
			for(int i = 0; i < h; ++i) {
				for(int j = 0; j < w; ++j) {
					s[i][j] = t[j][i];
				}
			}
			swap(s, t);
		}
		long a = 0;
		for(int u = 0; u < h; ++u) {
			for(int j = 0; j < w; ++j) {
				x[j] = 0;
			}
			for(int d = u; d < h; ++d) {
				for(int j = 0; j < w; ++j) {
					x[j] += (t[d][j] == '#' ? 1 : -1);
					s[j + 1] = s[j] + x[j];
				}
				for(int j = 0; j <= w; ++j) {
					a += cnt[s[j] + h * w] ++;
				}
				for(int j = 0; j <= w; ++j) {
					cnt[s[j] + h * w] = 0;
				}
			}
		}
		cout << a << endl;
	}
}

