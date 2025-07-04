#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
const int N=31;
int n;
string a;
pair <int,int> q[N];
int b[N];
int ans;
bool cmp(pair <int,int> a,pair <int,int> b){return a.second<b.second;}
signed main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>a;
	scanf("%d",&n);
	For(i,1,26) q[i].first=i;
	For(i,0,a.size()-1)
	{
		if(!q[a[i]-'a'+1].second) ans++;
		q[a[i]-'a'+1].second++;
	}
	sort(q+1,q+27,cmp);
	For(i,1,26)
	{
		if(q[i].second<n)
		{
			if(!q[i].second) continue;
			ans--;
			n-=q[i].second;
			q[i].second=0;
		}
		else break;	
	}
	sort(q+1,q+27);
	printf("%d\n",ans);
	For(i,0,a.size()-1)
	{
		if(q[a[i]-'a'+1].second)
		{
			--q[a[i]-'a'+1].second;
			printf("%c",a[i]);
		}
	}
	return 0;
}
