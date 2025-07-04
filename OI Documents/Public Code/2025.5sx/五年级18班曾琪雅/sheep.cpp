#include<bits/stdc++.h>
using namespace std;
int n,a[2010],cnt=0;
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==-1)
		{
			cnt++;
		}
	} 
	cout<<n-cnt;
	return 0;
}
