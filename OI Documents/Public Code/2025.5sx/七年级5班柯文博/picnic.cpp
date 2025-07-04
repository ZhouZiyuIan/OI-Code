#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
 	int a[100001],n,y,cnt=0,ans;
 	cin>>n>>y;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	 }
	for(int i=1;i<=n;i++)
	{
		ans=a[i]*a[i+1]*y/2;
		cnt++;
	}
	cout<<cnt;
	if(n==1) cout<<"0";
	return 0;
}

