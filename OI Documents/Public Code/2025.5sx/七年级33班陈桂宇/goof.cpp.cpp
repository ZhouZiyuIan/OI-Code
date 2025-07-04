#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,y,ans,len;
char s[N],d[N];
struct node
{
	int a;
	char b;
}vis[N];
bool cmp(node e,node f){
	return e.a<f.a;
}
signed main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s; 
	cin>>n;
	len=strlen(s);
	for(int i=0;i<len;i++) 
	{
		vis[s[i]-'a'].a++;
		vis[s[i]-'a'].b=s[i];
	}
	sort(vis,vis+26,cmp);
	for(int i=0;i<26;i++)
	{
		
		if(vis[i].a==0) continue;
		if(n-vis[i].a>=0)
		{
			n-=vis[i].a;
			vis[i].a=0;
		 } 
		else 
		{
			vis[i].a-=n;
			break;
		}
	}
	for(int i=25;i>=0;i--)
	{
		if(vis[i].a!=0)
		{
			ans++;
			for(int j=1;j<=vis[i].a;j++)
			{
				 cout<<vis[i].b;
			 } 
		 } 
	}
	cout<<endl<<ans;
	return 0;
}

