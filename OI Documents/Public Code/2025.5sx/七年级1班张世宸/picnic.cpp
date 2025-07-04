#include<bits/stdc++.h>
using namespace std;
long long n,y,a[100010],len;
double s,ans[100010];
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	if(y<0)
	y=0-y;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(y==0||n<=1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i+1<=n)
		for(int j=i+1;j<=n;j++)
			if(a[i]!=a[j])
			{
				double u=a[i],e=a[j];
				if(e>u)
				s=(e-u)*y/2;
				else
				s=(u-e)*y/2;
				if(len==0)
				{
					len++;
					ans[len]=s;
				}
				else
					for(int o=1;o<=len;o++)
						if(s==ans[o])
							break;
						else
							if(o==len)
							{
								len++;
								ans[len]=s;
								break;
							}
			}
	}
	cout<<len;
}
