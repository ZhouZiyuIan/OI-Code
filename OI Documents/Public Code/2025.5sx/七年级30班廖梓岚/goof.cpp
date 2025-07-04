#include <bits/stdc++.h>
using namespace std;
char a[500001],b[500001]={};
int k,c[30],n,m=0,q=0,num=0,w;
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>a>>k;
	int len=strlen(a);
	if(k>=len)
	{
		cout<<0<<endl<<b[0];
		return 0;
	}
	else
	n=len-k;
	for(int i=0;i<len;i++)
	c[a[i]-97]++;
	for(int i=0;i<26;i++)
	{
		num++;
		for(int j=0;j<26;j++)
		{
			if(q<c[j])
			{
				q=c[j];
				w=j;
			}
		}
		m+=q;
		c[w]=0;
		q=0;
		for(int j=0;j<len;j++)
		{
			if(a[j]==w+97)
			b[j]=a[j];
		}
		if(m>=n)
		break;
	}
	cout<<num<<endl;
	for(int i=0;i<len;i++)
	{
		if(b[i]!=0)
		cout<<b[i];
	}
	return 0;
}
