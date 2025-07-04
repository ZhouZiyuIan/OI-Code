#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e3+10;
int n,m,sum,a[MAXN],f[MAXN*MAXN+10],ans;
signed main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) f[++sum]=abs(a[i]-a[j]);
	sort(f+1,f+1+sum);
	for(int i=1;i<=sum;i++) if(f[i]!=f[i-1]) ++ans;
	printf("%lld",ans);
	return 0;
} 
