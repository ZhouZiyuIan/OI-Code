#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t;
ll n,s;
ll const maxn=200000;
ll l[maxn+1],r[maxn+1];
pair<ll,ll>p[maxn+1],pp[maxn+1];
ll y[maxn+1];
ll const inf=1000000000;
ll sm;
signed main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&s);
		sm=(n+1)/2;
		ll maxx=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld",&l[i],&r[i]);
			p[i]={l[i],r[i]};
			maxx=max(maxx,r[i]);
		}
		sort(p+1,p+n+1,[](pair<ll,ll>a,pair<ll,ll>b){
			return a.second<b.second;
		});
		ll l=1,r=maxx;
		ll mid;
		while(l<r){
			mid=(l+r+1)>>1;
			for(ll i=1;i<=n;i++){
				pp[i]=p[i];
				y[i]=p[i].second;
			}
			ll g=lower_bound(y+1,y+n+1,mid)-y;
			if(g>sm){
				r=mid-1;
				continue;
			}
			sort(pp+g,pp+n+1,[](pair<ll,ll>a,pair<ll,ll>b){
				return a.first<b.first;
			});
			ll use=0;
			for(ll i=1;i<sm;i++){
				use+=pp[i].first;
			}
			for(ll i=sm;i<=n;i++){
				use+=max(pp[i].first,mid);
			}
			if(use>s){
				r=mid-1;
				continue;
			}
			l=mid;
			continue;
		}
		printf("%lld\n",l);
	}
	
	
	return 0;
}
