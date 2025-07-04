#include<bits/stdc++.h>
#define endl '\n'
#define int int
#define rep(i,a,b) for(register int i(a);i<=b;++i)
#define ref(i,a,b) for(register int i(a);i>=b;--i)
#define rek(i,a,b) for(register int i(a);i<b;++i)
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int T,n,m,ans;
int vis[150];
struct Node
{
	int val,id;
}sum[150];
string s;
bool cmp(Node x,Node y)
{
	return x.val<y.val;
}
signed main()		
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>m,n=s.size();
	rek(i,0,n) ++sum[int(s[i])].val,sum[int(s[i])].id=int(s[i]),ans+=(sum[int(s[i])].val==1);
	sort(sum+97,sum+123,cmp);
	rep(i,97,122)
	{
		if(m>=sum[i].val&&sum[i].val) --ans;
		if(m>=sum[i].val) vis[sum[i].id]+=sum[i].val,m-=sum[i].val;
		else {vis[sum[i].id]+=m;break;}
	} 
	cout<<ans<<endl;
	rek(i,0,n)
	{
		if(vis[int(s[i])]) --vis[int(s[i])];
		else cout<<s[i];
	}
}
