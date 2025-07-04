#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,s,l,r,ans;
signed main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&s);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&l,&r);
			ans+=(l+r)/2;
		}
		printf("%lld",ans);
		puts("");
		ans=0;
	}
}
