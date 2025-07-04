#include<bits/stdc++.h>
#define int long long
#define rd read()
#define gc getchar()
using namespace std;
inline int read()
{
	int x=0,ss=1,ch=gc;
	while((ch<'0'||ch>'9')&&ch!='-')ch=gc;
	if(ch=='-')ss=-1,ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc;
	return x*ss;
}
const int N=100005,D=26;
int n,k,cnt[30],p[30],vis[30];string s;
inline bool cmp(int x,int y)
{
	return cnt[x]<cnt[y];
}
signed main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;int ans=26;k=rd;
	for(int i=0;i<s.size();i++)cnt[s[i]-'a'+1]++;
	for(int i=1;i<=26;i++)p[i]=i;
	sort(p+1,p+D+1,cmp);
	for(int i=1;i<=26;i++)if(k>=cnt[p[i]])k-=cnt[p[i]],vis[p[i]]=1,--ans;
	cout<<ans<<'\n';
	for(int i=0;i<s.size();i++)if(!vis[s[i]-'a'+1])cout<<s[i];
	return 0;
}
