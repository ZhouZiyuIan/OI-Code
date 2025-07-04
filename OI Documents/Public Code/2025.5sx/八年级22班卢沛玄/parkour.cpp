#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int t;
int n,m;
int const maxm=12;
int const maxn=11000;
int s[maxm+1][maxn+1];
int sx,sy;
int f[maxm+1][maxn+1];
signed main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		for(int i=0;i<=maxm;i++){
			for(int j=0;j<=maxn;j++){
				s[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char in=getchar();
				while(in!='.'&&in!='X'&&in!='s'){
					in=getchar();
				}
				if(in=='.'){
					s[i][j]=0;
				}
				if(in=='X'){
					s[i][j]=1;
				}
				if(in=='s'){
					sx=i;
					sy=j;
					s[i][j]=0;
				}
			}
		}
		for(int i=0;i<=maxm;i++){
			for(int j=0;j<=maxn;j++){
				f[i][j]=0;
			}
		}
		f[sx][sy]=1;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(f[i][j]==0){
					continue;
				}
				if(s[i][j+1]==1){
					continue;
				}
				if((s[i][j+1]|s[i][j+2]|s[i][j+3])==0){
					f[i][j+3]=1;
				}
				if((s[i+1][j+1]|s[i+1][j+2]|s[i+1][j+3])==0){
					f[i+1][j+3]=1;
				}
				if((s[i-1][j+1]|s[i-1][j+2]|s[i-1][j+3])==0){
					f[i-1][j+3]=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(f[i][m]|f[i][m+1]|f[i][m+2]|f[i][m+3]){
				ans=1;
			}
		}
		printf("%s\n",ans==1?"YES":"NO");
	}
	return 0;
}
