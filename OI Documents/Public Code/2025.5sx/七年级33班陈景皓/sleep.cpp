#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e6+5,X=1e3+5;
LL a[N],n,t,ans,u;
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>t;
	for(rint i=1;i<=n;++i){
		cin>>a[i];
		u+=a[i];
	}
	t%=u;
	if(t==0){
		cout<<n<<'\n'<<0;
		return 0;
	}
	for(int i=1;i<=n;++i){
		ans+=a[i];
		if(ans>=t){
			cout<<i<<'\n'<<ans-t;
			return 0;
		}
	}
	return 0;
}
