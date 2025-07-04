#include<bits/stdc++.h>
using namespace std;
map<int,bool> vis;
long long int n,m,d,c,a[2000010],sum=0,ans=0;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(i!=j&&!vis[max(abs(a[i]),abs(a[j]))-min(abs(a[i]),abs(a[j]))]) vis[max(abs(a[i]),abs(a[j]))-min(abs(a[i]),abs(a[j]))]=1,ans++;
	cout<<ans<<endl;
	return 0;
}
