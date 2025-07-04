#include<bits/stdc++.h>
using namespace std;
int k,ans=26,z,mark;
struct su
{
	char c;
	int s;
}mp[30],mp1[30];
string s;
bool cmp(su a,su b)
{
	return a.s<b.s; 
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>k;
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]-'a'+1].c=s[i];
		mp[s[i]-'a'+1].s++;
	}
	sort(mp+1,mp+1+26,cmp);
	for(int i=1;i<=26;i++)
	{
		if(k-mp[i].s<0)
		{
			break;
		}
		k-=mp[i].s;
		mp[i].s=0;
		ans--;
	}
	cout<<ans<<endl;
	for(int i=0;i<s.size();i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(mp[j].c==s[i])
			{
				if(mp[j].s>0&&z+1<s.size())
				{
					cout<<s[i];
				}
				z++;
				break;
			}
		}
	}
	return 0;
}
