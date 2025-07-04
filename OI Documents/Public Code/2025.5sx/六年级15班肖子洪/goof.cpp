#include<bits/stdc++.h>
using namespace std;
int n;
int len;
int b[101010];
char s[101010];
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	len=strlen(s);
	cin>>n;
	if(n>len)
	{
		cout<<0;
		return 0;
	}
	if(n==0)
	{
		cout<<0<<"\n";
		cout<<s;
		return 0;
	}
	cout<<0;
	cout<<s;
}

