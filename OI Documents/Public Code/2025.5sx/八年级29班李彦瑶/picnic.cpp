#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,y;
ll x[1005],ans;
map<int,ll> vis;
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int tmp=abs(x[i]-x[j]);
			if(!vis[tmp]) ans++;
			vis[tmp]=1;
		}
	}
	printf("%lld",ans);
	return 0;
}
