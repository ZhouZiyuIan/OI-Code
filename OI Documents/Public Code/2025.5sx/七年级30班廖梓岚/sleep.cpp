#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
long long t;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	long long m=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m+=a[i];
	}
	while(t>m)
	t-=m; 
	for(int i=0;i<n;i++)
	{
		if(a[i]<t)
		t-=a[i];
		else
		{
			cout<<i+1<<endl<<a[i]-t;
			break;
		}
	}
	return 0;
}

