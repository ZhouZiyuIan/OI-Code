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
int n,y;
int a[N];
//bitset<4000000000> mp;
map<int,int> mp;
signed main()
{
	//	freopen("data11.in","r",stdin);
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	n=rd,y=rd;
	//cin>>n>>y;
	int ans=0;
	for(int i=1;i<=n;i++)a[i]=rd;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!mp[abs(a[i]-a[j])])mp[abs(a[i]-a[j])]=1,++ans;
	cout<<ans;
	return 0;
}
