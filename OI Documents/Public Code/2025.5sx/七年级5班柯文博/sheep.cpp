#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int n,x,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
	}
	for(int i=1;i<=n;i++)
	{
		if(x>0) cnt++;
	}
	cout<<cnt;
}

