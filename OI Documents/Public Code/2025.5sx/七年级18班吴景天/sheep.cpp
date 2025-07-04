#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mode=1000000007;
ll n,a[2010],z,ans;
bool vis[2010],b[2010];
void dfs(ll k);
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=-1) vis[i]=1,b[i]=1;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
void dfs(ll k){
	if(k==n+1){
		ans++;
		ans%=mode;
	}
	else if(a[k]!=-1) dfs(k+1);
	else for(ll i=1;i<=n;i++){
		if(a[k]==-1&&(!vis[i])&&i!=k){
			a[k]=i;
			vis[i]=1;
			dfs(k+1);
			a[k]=-1;
			vis[i]=0;
		}
	}
}

