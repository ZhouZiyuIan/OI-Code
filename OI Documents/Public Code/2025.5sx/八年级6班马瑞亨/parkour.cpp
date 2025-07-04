#include<bits/stdc++.h>
using namespace std;
int n,m,st_x,st_y,flag;
int dx[4]={0,-1,0,1};
char s[10005][15];
void dfs(int x,int y) {
	if(flag==1) return;
	if(y==n) {
		cout<<"YES\n";
		flag=1;
		return;
	}
	y++;
	if(s[x][y]=='X') return;
	for(int i=1;i<=3;i++) {
		int xx=x+dx[i],yy=y+2;
		if(xx<1||xx>m||s[xx][yy]=='X'||s[xx][yy-2]=='X') continue;
		if(yy>=n) {
			cout<<"YES\n";
			flag=1;
			return;
		}
		dfs(xx,yy);
	}
}
int main() {
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1;i<=m;i++) {
			scanf("%s",s[i]+1);
			if(s[i][1]=='s') {
				st_x=i;
				st_y=1;
			}
		}
		dfs(st_x,st_y);
		if(flag==0) {
			cout<<"NO\n";
		}
		flag=0;
	}
	return 0;
}
