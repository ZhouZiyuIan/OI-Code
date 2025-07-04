#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1005],d[1005],k[10000005],m;
int main()
{
		freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
cin>>a>>b;
for(int i=1;i<=a;i++)
{
	cin>>c[i];
}
for(int i=1;i<=a;i++)
{
	for(int j=1;j<=a;j++)
	{
		k[abs(c[i]-c[j])]++;
		if(k[abs(c[i]-c[j])]==1)
		{
			m++;
		}
	}
}
cout<<m-1;
	return 0;
}

