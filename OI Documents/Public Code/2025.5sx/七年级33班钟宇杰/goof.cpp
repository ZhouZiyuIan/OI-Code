#include<bits/stdc++.h>
using namespace std;
int k;
struct AC
{
	int id;
	int gs;
}T[35];
int u[35];
bool cmp(AC a,AC b)
{
	return a.gs<b.gs;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	string s;
	cin>>s>>k;
	int n=s.size();
	s=" "+s;
	k=min(n,k);
	for(int i=1;i<=26;i++) T[i].id=i;
	for(int i=1;i<=n;i++) T[s[i]-'a'+1].gs++;
	sort(T+1,T+26+1,cmp);
	int ans=0;
	for(int i=1;i<=26;i++)
	{
		u[T[i].id]=min(k,T[i].gs);
		ans=ans+(T[i].gs!=u[T[i].id]);
		k=max(0,k-T[i].gs); 
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(u[s[i]-'a'+1]) u[s[i]-'a'+1]--;
		else cout<<s[i];
	}
}
