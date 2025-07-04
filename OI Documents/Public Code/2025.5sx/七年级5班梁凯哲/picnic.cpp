#include<bits/stdc++.h>
using namespace std;
long long a[100000005],y,n,ans,b[100000005];
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long  z=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]!=a[i]) 
			{
				b[z]=a[j]-a[i];
				z++;
			}
		}
	}
	sort(b,b+z);
	for(int i=1;i<z;i++)
	{
		if(b[i]!=b[i+1]) ans++;	
	}
	cout<<ans;
	return 0;
}
