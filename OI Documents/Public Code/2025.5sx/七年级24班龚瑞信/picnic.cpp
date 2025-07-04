#include<bits/stdc++.h>
#define endl '\n'
#define int int
#define rep(i,a,b) for(register int i(a);i<=b;++i)
#define ref(i,a,b) for(register int i(a);i>=b;--i)
#define rek(i,a,b) for(register int i(a);i<b;++i)
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int T,n,m,ans; 
long long a[1005];
map<long long,int> vis;
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	Tie,cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			long long dis=a[i]>a[j]?a[i]-a[j]:a[j]-a[i];
			if(dis>0&&!vis[dis]) ++ans,vis[dis]=1;
		}
	}
	cout<<ans;
}
