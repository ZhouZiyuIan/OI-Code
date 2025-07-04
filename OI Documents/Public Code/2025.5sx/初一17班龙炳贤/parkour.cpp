#include<bits/stdc++.h>
using namespace std;
int t,n,m,mar;
char maz[15][10005];
void dfs(int x,int y) {
	if(y >= n - 1) {
		mar = 1;
		return ;
	}
	if(maz[x][y + 1] != 'X') {
		if(x + 1 <= m && maz[x + 1][y + 1] != 'X' && maz[x + 1][y + 3] != 'X') {
			dfs(x + 1,y + 3);
			if(mar) return ;
		}
		if(x - 1 >= 1 && maz[x - 1][y + 1] != 'X' && maz[x - 1][y + 3] != 'X') {
			dfs(x - 1,y + 3);
			if(mar) return ;
		}
		if(maz[x][y + 3] != 'X') {
			dfs(x,y + 3);
			if(mar) return ;
		}
	}
}
int main() {
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	for(int i = 1;i <= t;i++) {
		cin>>n>>m;
		for(int j = 1;j <= m;j++) {
			cin>>maz[j];
		}
		int tmp;
		for(int j = 1;j <= m;j++) {
			if(maz[j][0] == 's') {
				tmp = j;
				break;
			}
		}
		mar = 0;
		dfs(tmp,0);
		if(mar) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}
