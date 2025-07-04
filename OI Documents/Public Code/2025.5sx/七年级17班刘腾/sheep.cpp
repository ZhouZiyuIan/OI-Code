#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2005],b[2005],cnt,p[2005],cut,ans;
bool vis[2005];
const int mod=1000000007;
bool fun(){
	for(int i=1;i<=cut;i++){
		if(p[i]==i)return 0;
	}
	return 1;
}
void dfs(int x){
	if(x>cnt){
		if(fun()){
			ans=ans%mod+1;
		}
		return;
	}
	for(int i=1;i<=cnt;i++){
		if(!vis[i]){
			vis[i]=1;
			p[++cut]=b[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==-1)continue;
		b[++cnt]=a[i];
	}
	dfs(1);
	printf("%lld",ans%mod);
}
