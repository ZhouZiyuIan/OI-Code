#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
char ma[5001][5001];
int main() {
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>ma[i][j];
			}
		}
		bool l=1;
		for(int i=1; i<=m; i++) {
			bool p=0;
			for(int j=1; j<=n; j++) {
				if(ma[j][i]!='.') {
					p=1;
					break;
				}
			}
			if(!p) {
				l=0;
			}
		}
		if(!l) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
