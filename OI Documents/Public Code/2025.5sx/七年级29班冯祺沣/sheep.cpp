#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
void fre()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
}
int n,sum;
map<int,int> a,vis;
void dfs(int k)
{
	if(k>n) sum=(sum+1)%mod;
	else if(a[k]!=-1) dfs(k+1);
	else for(int i=1;i<=n;i++) if(vis[i]!=-1&&i!=k) vis[i]=-1,dfs(k+1),vis[i]=0;
}
int main()
{
	fre();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],vis[a[i]]=-1;
	dfs(1);
	cout<<sum;
	return 0;
}
