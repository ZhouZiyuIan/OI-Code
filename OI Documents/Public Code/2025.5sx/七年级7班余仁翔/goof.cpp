#include<bits/stdc++.h>
using namespace std;
char a[100005];
long long b,c,d,e,f,g,h[1005],ans,k[1005],l[1005],m,m1,o[1005],u[1005],p1;
int main()
{
		freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>a;
	cin>>b;
	c=strlen(a);
	for(int i=0;i<c;i++)
	{
		if(h[a[i]]==0)
		{
			m1++;
		}
		h[a[i]]++;
		l[a[i]]++;
	}
	sort(h+1,h+'z'+1);
	for(int i='a';i<='z';i++)
	{
		if(h[i]!=0)
		{
		b=b-h[i];
		if(b<0)
		{
			ans=e;
			p1=1;
			break;
		}
		e++;
		k[e]=h[i];
		}
	
	}
	if(p1==0)
	{
		ans=m1;
	}
	cout<<m1-ans<<"\n";
		for(int j='a';j<='z';j++)
		{
			for(int i=1;i<=e;i++)
	{
			if(l[j]==k[i]&&u[i]==0)
		{
			k[i]=j;
			u[i]=1;
			break;
		}
			}
		}

	m1=0;
	for(int i=0;i<c;i++)
	{
		for(int j=1;j<=e;j++)
		{
			if(a[i]==k[j])
			{
				m1=1;
			}
		}
		if(m1==0)
		{
			cout<<a[i];
		}
		m1=0;
	}
	return 0;
}

