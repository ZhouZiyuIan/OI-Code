#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,unordered_map<int,int>>c;
int T, d[300001] = {1}, h, w, tmp , a, v;
string s[25001], t[25001];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> h >> w;
		for(int i = 0; i < h; ++i) {
			cin >> s[i];
		}
		if(h > w){
			for(int i = 0; i < h; ++i) {
				for(int j = 0; j < w; ++j) {
					t[j][i]=s[i][j];
				}
			}
			tmp = h;
			h = w;
			w = tmp;
			for(int i = 0; i < h; ++i) {
				s[i] = t[i];
			}
		}
		for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) {
				c[i][j] = (s[i][j] == 35 ? -1 : 1) + c[(i - 1 + h) % h][j] + c[i][(j - 1 + w) % w] - c[(i - 1 + h) % h][(j - 1 + w) % w];
			}
		}
		a = 0;
		for(int sx = 0; sx < h; ++sx) {
			for(int tx = sx; tx < h; ++tx) {
				for(int l = 0; l < w; ++l) {
					v = c[tx][l] - c[(sx - 1 + h) % h][l];
					a += d[v];
					d[v]++;
				}
				for(int l = 0; l < w; ++l) {
					d[c[tx][l] - c[(sx - 1 + h) % h][l]]--;
				}
			}
		}
//		cout<<"asdddddddddddddddddddddddddddddddddddddddddd"<<endl;
		cout << a << endl;
	}
}
