#include<bits/stdc++.h>
using namespace std;
string s;
struct edge{
	char x;
	int now;
}vis[27];
int n,m,k,t,d,c,sum=0,ans=0,a[100010];
bool cmp(edge x,edge y)
{
	return x.now<y.now;
}
void find(char x)
{
	for(int i=0;i<s.size();i++) if(s[i]==x) s[i]=NULL;
	return;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	for(int i=1;i<=26;i++) vis[i].x=char(i+'a'-1});
	cin>>s>>n;
	for(int i=0;i<s.size();i++) vis[s[i]-'a'+1].now++;
	sort(vis+1,vis+27,cmp);
	for(int i=1;i<=26;i++) if(n>=vis[i].now) find(vis[i].x),n-=vis[i].now;
	for(int i=0;i<s.size();i++) if(!a[s[i]]&&s[i]) a[s[i]]=1,ans++;
	cout<<ans<<endl;
	for(int i=0;i<s.size();i++) if(s[i]) cout<<s[i];
	return 0;
}
