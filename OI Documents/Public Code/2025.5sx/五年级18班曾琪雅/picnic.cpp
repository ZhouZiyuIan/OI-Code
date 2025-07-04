#include<bits/stdc++.h>
using namespace std;
unsigned long long n,y,x[100001];
unsigned long long cnt=1,sum=1;
unsigned long long f[100001];
unsigned long long ans=0;
void dfs(int a)
{
	if(a>n)
	{
		return;
	}
	for(unsigned long long j=1;j<=n-a;j++)
	{
		double g=(x[a+j]-x[a])*y;
		f[cnt]=g;
		cnt++;
	}
	dfs(a+1);
}
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);	
	cin>>n>>y;
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	dfs(1);
	cnt--;
	int r=1;
	while(r!=cnt)
	{
		for(int i=r+1;i<=cnt;i++)
		{
			if(f[r]==f[i])
			{
				ans++;
			}
		}
		r++;
	}
	cout<<cnt-ans;
	return 0;
}

