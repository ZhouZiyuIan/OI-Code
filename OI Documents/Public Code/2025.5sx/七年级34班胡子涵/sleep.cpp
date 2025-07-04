#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,t,sum;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	t=t%sum;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<t)
		{
			t-=a[i];
		}
		else
		{
			cout<<i<<endl<<a[i]-t;
			return 0;
		}
	}
}
