#include<bits/stdc++.h>
using namespace std;
int dy[3]={0,1,-1};
bool vist[1020][1020];
int t,n,m,p,q,flag=0;
char ch[1020][1020];
void dfs(int x,int y){
	if(x==m&&y==n){
		flag=1;
		return;
	}
	for(int i=0;i<3;i++){
		int nx=x+1;
		int ny=y+dy[i];
		if(vist[nx][ny]==0&&ch[nx][ny]!='X'){
			vist[nx][ny]=1;
			dfs(nx,ny);
			vist[nx][ny]=0;
		}
	}
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&ch[i][j]);
				if(ch[i][j]=='s'){
					p=i;
					q=j;
				}
			}
		}
		dfs(p,q);
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}continue;
	}
}

