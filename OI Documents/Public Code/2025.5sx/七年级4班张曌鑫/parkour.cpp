#include<bits/stdc++.h>
using namespace std;
int x[4]={1,0,0},y[4]={0,1,-1};
int t,n,m,l,c;
char a[21][10010];
int vis[21][10010];
bool e=false;
void dfs(int qx,int qy){
	if(qx==n-1){
		e=true;
		return ;
	}
	else if(vis[qx][qy]==0){
		return ;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int nx=qx+x[i],ny=qy+y[j];
			if(nx>0&&ny>0&&nx<n&&ny<m){
				dfs(nx,ny);
			}
		}
	}
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		for(int q=0;q<m;q++){
			for(int j=0;j<n;j++){
				cin>>a[q][j];
				if(a[q][j]=='#'){
					vis[q][j]=0;
				}
				else if(a[q][j]=='s'){
					l=q;
					c=j;
				}
				else{
					vis[q][j]=1;
				}
			}
		}
		e=false;
		dfs(c,l);
		if(e)
		{
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}
