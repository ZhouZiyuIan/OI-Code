#include<bits/stdc++.h>
using namespace std;
int t,n,m,st;
bool f[10001][12],fl;
string mp[12];
bool pd(int x,int y){
	return mp[x][min(y,n)]=='X';
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>mp[i];
			mp[i]+='.';
			if(mp[i][0]=='s')st=i;
		}
		for(int i=0;i<n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
		f[0][st]=!pd(st,1);
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i-1][j+1];
				if(pd(j,i*3)||pd(j,i*3-1)||pd(j,i*3-2)||pd(j,i*3+1))f[i][j]=0;
			}
		}
		fl=0;
		for(int j=1;j<=m;j++){
			if(f[n-1][j]){
				fl=1;
				break;
			}
		}
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
}

