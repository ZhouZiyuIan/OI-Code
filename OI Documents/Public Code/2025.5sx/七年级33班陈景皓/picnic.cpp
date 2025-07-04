#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e6+5,X=1e3+5;
LL ans,n,x[X],y,u;
map<LL,LL>mp;
signed main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>y;
	for(rint i=1;i<=n;++i)cin>>x[i];
	for(rint i=1;i<=n;++i){
		for(rint j=1;j<i;++j){
			u=abs(x[i]-x[j]);
			if(u&&(!mp[u]))ans++,mp[u]=1;
		}
	}
	cout<<ans;
	return 0;
}

