#include <bits/stdc++.h>
using namespace std;
int n,y,a[1001],m[1001],b=0,num=1;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=0;i<n;i++)
	cin>>a[i];
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			m[b]=a[j]-a[i];
			b++;
		}
	}
	sort(m,m+b);
	for(int i=1;i<b;i++)
	{
		if(m[i]!=m[i-1])
		num++;
	}
	cout<<num;
	return 0;
}
