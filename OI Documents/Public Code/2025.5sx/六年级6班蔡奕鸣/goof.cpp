#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
char s[100005];
int t,n,sum[10005],tot,ans,vis[100005];
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	cin>>t;
	n = strlen(s);
	for(int i = 0;i < n;i++)
	{
		sum[s[i]-'a'+1]++;
		if(!vis[s[i]])
		{
			vis[s[i]] = 1;
			ans++;
		}
	}
	sort(sum+1,sum+25,cmp);
	for(int i = 24;i >= 1;i--)
	{
		if(sum[i] <= t && sum[i] != 0)
		{
			t -= sum[i];
			sum[i] = 0;
			ans--;
		}
		else if(sum[i] != 0)
		{
			sum[i] -= t;
			break;
		}
	}
	cout<<ans<<endl;
	for(int i = 0;i < n;i++)
	{
		if(sum[i] >= 1)
		{
			sum[i]--;
			cout<<s[i];
		}
	}
	return 0;
}
