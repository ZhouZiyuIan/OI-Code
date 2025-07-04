#include<bits/stdc++.h>
#define int long long
using namespace std;
void fre()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
}
int n,cnt,k;
int a[30501];
map<int,int> num;
signed main()
{
	fre();
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			num[abs(a[j]-a[i])]++,cnt+=(num[abs(a[j]-a[i])]==1);
	cout<<cnt;
	return 0;
}
