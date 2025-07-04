#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int n,ln,ans=1;
ll y,a[N],b[N*N*2];
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%lld",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==1)
	{
		printf("0");
		return 0;
	}
//	printf("1");
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]!=a[j]) b[++ln]=abs(a[i]-a[j]);
		}
	}
	sort(b+1,b+1+ln);
	for(int i=2;i<=ln;i++)
		if(b[i]!=b[i-1]) ans++;
	printf("%d",ans);
	return 0; 
}
