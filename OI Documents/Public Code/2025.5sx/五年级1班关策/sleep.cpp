#include<bits/stdc++.h>
using namespace std;
long long n,a[100005];
long long sum,t,z,j=1;
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
	z=t%sum;
	while(z>0)
	{ 
		if(z-a[j]<=0)
		{
			cout<<j<<endl;
			cout<<a[j]-z;
			break;
		}
		z-=a[j];
		j++;
	}
	return 0;
}
