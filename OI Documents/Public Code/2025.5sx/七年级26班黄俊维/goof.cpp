#include<bits/stdc++.h>
using namespace std;
int k;
long long len,m,kind=1e9,ans_len;
char s[100005],tmp[100005];
char ans[100005];
void judge(int l)
{
	long long vis[1005];
	long long sum=0;
	for(int i='a';i<='z';i++)
	{
	    vis[i]=0;
	}
	for(int i=1;i<=l;i++)
	{
		if(vis[tmp[i]]==0)
		{
			vis[tmp[i]]++;
			sum++;
		}
	}
	if(sum<kind)
	{
		kind=sum;
	    for(int i=1;i<=l;i++)
	    {
		    ans[i]=tmp[i];
	    }
	    ans_len=l;
	}
	return ;
}
void dfs(int x,int tot)
{
	if(x>len)
	{
		if(tot<k)
		{
			return ;
		}
		judge(tot);
		return ;
	}
	tmp[tot]=s[x];
	dfs(x+1,tot+1);
	tmp[tot]=' ';
	dfs(x+1,tot);
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
    cin>>s+1;
    cin>>k;
    len=strlen(s+1);
    if(len<=k)
    {
    	cout<<m<<endl;
    	cout<<ans[1];
    	return 0;
	}
	dfs(1,1);
	cout<<kind<<endl;
	for(int i=1;i<=ans_len;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
