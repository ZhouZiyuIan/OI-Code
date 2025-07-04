#include<bits/stdc++.h>
using namespace std;
long long t,a[100000005],h,n;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		h+=a[i];
	}
	if(t>h)
	{
		while(t>h)
		{
			t-=h;
		}
		t+=h;
	}
	for(int i=1;i<=n;i++)
	{
		if(t>a[i]) t-=a[i];
		else 
		{
			cout<<i<<" "<<a[i]-t;
			return 0;
		}
	}
}
