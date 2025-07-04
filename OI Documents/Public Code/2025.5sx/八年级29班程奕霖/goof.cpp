#include<bits/stdc++.h>
using namespace std;
string s;
int n,k;
int bz[100];
struct Node
{
	int val,id;
}a[100];
inline bool cmp(Node A,Node B)
{
	return A.val<B.val;
}
signed main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>k;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
		bz[s[i]-'a'+1]++;
	for(int i=1;i<=26;i++)
	{
		a[i]={bz[i],i};
	}
	sort(a+1,a+1+26,cmp);
	for(int i=1;i<=26;i++)
	{
		if(a[i].val<=k)
		{
			k-=a[i].val;
			bz[a[i].id]=0;
		}
		else
		{
			bz[a[i].id]=a[i].val-k;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=26;i++)
	{
		if(bz[i]>0) ans++;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
	{
		if(bz[s[i]-'a'+1]>0)
		{
			putchar(s[i]);
			bz[s[i]-'a'+1]--;
		}
	}
}
