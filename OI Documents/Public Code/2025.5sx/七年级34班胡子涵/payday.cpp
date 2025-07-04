#include<bits/stdc++.h>
using namespace std;
struct id{
	int l,r;
}tong[100001];
int ans,a[100001],n,s;
void dfs(int x,int sum)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		if(sum<=s)
		{
//			cout<<x<<endl;
			sort(a+1,a+1+n); 
			for(int i=1;i<=n;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
			ans=max(ans,a[(n+1)/2]);
		}
		return ; 
	}
	for(int i=tong[x].l;i<=tong[x].r;i++)
	{
		a[x]=i;
		dfs(x+1,sum+i);
		a[x]=0;
	}
}
void fun()
{
	ans=0;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>tong[i].l>>tong[i].r;
	}
//	sort(tong+1,tong+1+n)
	dfs(1,0);
	cout<<ans<<endl;
}
int main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		fun();
	}
}
