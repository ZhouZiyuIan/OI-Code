#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,f,vis[10005][15],t;
char s[15][10005];
void dfs(int x,int y){
	if(y>=n){
		f=1;
		return;
	}
	if(vis[x][y]){
		return;
	}
	if(x>1 && !vis[x-1][y+1] && s[x-1][y+2]!='x' && s[x-1][y+3]!='x'){
		vis[x-1][y+1]=1;
		dfs(x-1,y+3);
		vis[x-1][y+1]=0;
	}
	if(x<m && !vis[x+1][y+1] && s[x+1][y+2]!='x' && s[x+1][y+3]!='x'){
		vis[x+1][y+1]=1;
		dfs(x+1,y+3);
		vis[x+1][y+1]=0;
	}
	if(!vis[x][y+1] && s[x][y+2]!='x' && s[x][y+3]!='x'){
		vis[x][y+1]=1;
		dfs(x,y+3);
		vis[x][y+1]=0;
	}
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour,out","w",stdout);
	scanf("%d",&t);
	while(t--){
		f=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%s",s[i]+1);
			if(s[i][1]=='s') x=i;
		}
		dfs(x,1);
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
