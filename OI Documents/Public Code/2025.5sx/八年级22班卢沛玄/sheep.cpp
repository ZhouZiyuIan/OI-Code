#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const mod=1000000000+7;
int n;
int const maxn=2000;
int a[maxn+1];
pair<int,int>g[maxn+1];
int cnt;
int u[maxn+1];
int ans;
void dfs(int a){
	if(a>cnt){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]||i==g[a].second){
			continue;
		}
		u[i]=1;
		dfs(a+1);
		u[i]=0;
	}
}
signed main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==-1){
			cnt++;
			g[cnt]={a[i],i};
		}
		else{
			u[a[i]]=1;
		}
	}
	dfs(1);
	printf("%d",ans);
	
	
	return 0;
}
