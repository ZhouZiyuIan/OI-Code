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
const int N=100005;
int n,t;
int a[N],sum;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	n=rd,t=rd;
	for(int i=1;i<=n;i++)a[i]=rd,sum+=a[i];
	t%=sum;sum=0;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]>=t){cout<<i<<'\n'<<sum+a[i]-t<<'\n';return 0;}
		sum+=a[i];
	}
	return 0;
}
