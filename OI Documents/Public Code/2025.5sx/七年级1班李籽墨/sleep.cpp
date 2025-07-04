#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	long long n,t,i;
	cin>>n>>t;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	i=-1;
	while(t>0)
	{
		i++;
		if(i>=n)
		{
			i=0;
		}
		t-=a[i];
	}
	cout<<i+1<<" "<<0-t;
	return 0;
}
