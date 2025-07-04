#include<bits/stdc++.h>
using namespace std;
long long n,t,x,q,sum,a;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	
	for(long long i=1;i<=n;i++)
	{
		cin>>x;
	}
	for(long long i=1;i<=n;i++)
	{
		q+=i;
		if(t<=q) 
		{
			sum=q-t;
			a=i;
		}
		if(t>=q)
		{
			if(t-q==i)
			{
				sum=0;
			}
			a=i-1;
		}
	}
	cout<<a<<endl<<sum;
 	return 0;
}

