#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e6+5,X=2e3+5;
const LL mod=1e9+7;
LL n,x,y,ans;
LL a[X],f[X],b[X],s[X];
signed main(){
//	freopen("sheep.in","r",stdin);
//	freopen("sheep.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(rint i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==-1)++x;
	}
	y=n-x;
	f[2]=1;
	s[2]=1;
	for(rint i=3;i<=x;++i){
		f[i]=s[i-1]*2%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	cout<<f[x];
	return 0;
}

