#include<bits/stdc++.h>
using namespace std;
long long s[100000000];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	long long n,t;
	cin>>n>>t;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	long long j=0,sam=0;
	for(long long j=1;j<=n;j++)
	{
		sam=sam+s[j];
		if(sam>=t)
		{
			cout<<j<<endl<<sam-t;
			break;
		}
		if(j==n)
		{
			j=0;
		}
	}
}
