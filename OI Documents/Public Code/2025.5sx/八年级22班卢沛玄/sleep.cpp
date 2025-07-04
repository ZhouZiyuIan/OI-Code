#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t;
ll const maxn=100000;
ll x[maxn+1];
ll k;
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		k+=x[i];
	}
	t%=k;
	ll l=1;
	while(t>x[l]){
		t-=x[l];
		l++;
	}
	printf("%lld\n%lld",l,x[l]-t);
	
	
	return 0;
}
