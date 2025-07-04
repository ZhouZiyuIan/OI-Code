#include<bits/stdc++.h>
using namespace std;
long long k,ans;
char s[101010];
int sum[101010];
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>k;
	int len=strlen(s);
	if(len<=k)
	{
		cout<<0<<"\n";
		return 0;
	}
	cout<<1<<"\n"<<s;
}

