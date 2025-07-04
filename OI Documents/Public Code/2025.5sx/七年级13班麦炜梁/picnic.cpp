#include<bits/stdc++.h>
using namespace std;
long long n,y,x[100000],t=1;
double ans,anq[10000000];
int abc(int a,int b)
{
	int w;
	if(a-b<0)
	{
		w=-a+b;
		return w;
	}
	else
	{
		return a-b;
	}
}
int main()
{
    freopen("picnic.in","r",stdin);
    freopen("picnic.out","w",stdout);
    cin>>n>>y;
for(int i=1;i<=n;i++)
{
	cin>>x[i];
}
if(n<=1)
{
	cout<<"0";
	return 0;
}
for(int j=1;j<=n;j++)
{
	for(int k=j+1;k<=n;k++)
	{
		if(x[j]>x[k])
		{
			ans=abc(x[j],x[k])*1.0;
		}
		else
		{
			ans=abc(x[k],x[j])*1.0;
		}
		ans=ans*y*1.0/2;
		for(int g=1;g<=t;g++)
		{
			if(ans==anq[g])
			{
				break;
			}
			else if(g==t&&anq[g]!=ans)
			{
				anq[g]=ans;
				t++;
				break;
			}
		}
	}
	}    
	cout<<t-1;
	return 0;
}
