#include<unordered_map>
#include<algorithm>
#include<stdio.h>
using namespace std;
using ll=long long;
unordered_map<ll,ll>mp;
ll n,a,b,c,d;
int t;
ll dfs(ll n){
	if(mp.count(n))return mp[n];
	ll m=min({dfs(n>>1)+a+n%2*d,dfs((n+1)>>1)+a+(2-n%2)%2*d,dfs(n/3)+b+n%3*d,dfs((n+2)/3)+b+(3-n%3)%3*d,dfs(n/5)+c+n%5*d,dfs((n+4)/5)+c+(5-n%5)%5*d});
	if(m/d>=n)return mp[n]=n*d;
	return mp[n]=m;
}
int main(){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
		mp.clear();
		mp[0]=0;
		mp[1]=d;
		printf("%lld\n",dfs(n));
	}
}
