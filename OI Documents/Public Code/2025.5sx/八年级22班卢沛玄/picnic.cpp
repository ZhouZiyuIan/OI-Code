#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
double y;
ll const maxn=1000;
double x[maxn+1];
ll ans;
map<double,ll>mp;
signed main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lf",&n,&y);
	for(ll i=1;i<=n;i++){
		scanf("%lf",&x[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			double g=0.5*abs(x[i]-x[j])*y;
			if(!mp.count(g)){
				ans++;
				mp[g]=1;
			}
		}
	}
	printf("%lld",ans);
	
	
	return 0;
}
