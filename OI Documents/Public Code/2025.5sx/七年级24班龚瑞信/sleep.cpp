#include<bits/stdc++.h>
#define endl '\n'
#define int int
#define rep(i,a,b) for(register int i(a);i<=b;++i)
#define ref(i,a,b) for(register int i(a);i>=b;--i)
#define rek(i,a,b) for(register int i(a);i<b;++i)
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int T,n,o;
int a[100005];
long long m,s;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	Tie,cin>>n>>m;
	rep(i,1,n) cin>>a[i],s+=a[i];
	m%=s;
	while(o<n)
	{
		if(m>a[++o]) m-=a[o];
		else
		{
			a[o]-=m;
			break;
		}
	}	
	cout<<o<<endl<<a[o];
}
