#include<bits/stdc++.h>
using namespace std;
long long n,t,sum,ans;
int a[101010];
int main()
{
//	freopen("sleep.in","r",stdin);
//	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	ans=t%sum;
	for(int i=1;i<=n;i++)
	{
		if(ans>a[i])
		{
			ans-=a[i];
			continue;
		}
		if(ans==a[i])
		{
			cout<<i<<' '<<"0";
			return 0;
		}
		if(ans<a[i])
		{
			cout<<i<<' '<<a[i]-ans;
			return 0;
		}
	}
}
