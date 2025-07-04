#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	char c[26],a[100100],n;
	long long k,len,leng,b[26],x,y=-999,sum=0,m=0;
	cin>>a>>k;
	len=strlen(a);
	leng=len;
	if(len<=k)
	{
		cout<<"0"<<endl;
		cout<<" ";
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		x=a[i];
		b[x-97]++;
		
	}
	for(int i=0;i<26;i++)
	{
		c[i]='*';
	}
	while(len-y>k)
	{
		for(int i=0;i<leng;i++)
		{
			if(b[i]>y)
			{
				x=i; 
				n=x;
				n+='a';
				y=b[i];
			}
		}
		if(len-y>k)
		{
			len-=y;
			b[x]=0;
			c[x]=n;
			y=-999;
			sum++;
		}
		else if(len-y<k)
		{
			m=k-(len-y);
		}
		else if(sum==0)
		{
			c[x]=n;
		}
	}
	cout<<sum+1<<endl;
	for(int i=0;i<leng;i++)
	{
		x=a[i];
		x-=97;
		if(c[x]!='*')
		{
			cout<<a[i];
		}
		else if(m!=0)
		{
			cout<<a[i];
			m--;
		}
	}
}
