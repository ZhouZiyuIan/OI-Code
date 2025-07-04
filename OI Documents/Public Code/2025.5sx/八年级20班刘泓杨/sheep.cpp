#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e3+10,MOD=1e9+7;
int n,m,sum,a[MAXN],t[MAXN],f[3][MAXN],w=1,s=1;
signed main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=-1) t[a[i]]=1;
	}
	while(a[s]!=-1) ++s;
//	t[s]=1,++s;
//	while(a[s]!=-1) ++s;
	for(int i=1;i<=n;i++) if(!t[i]&&i!=s) f[0][i]=1,++sum;
	for(int i=s+1;i<=n;i++,w^=1){
//		cout<<i<<" "<<sum<<endl;
		if(a[i]!=-1) continue;
		for(int j=1;j<=n;j++){
			if(t[j]||j==i) continue;
			f[w][j]=(sum-f[w^1][j]+MOD)%MOD;
		}
		sum=0;
		for(int j=1;j<=n;j++) if(!t[j]&&j!=i) sum=(sum+f[w][j])%MOD;
	}
	printf("%lld",sum);
	return 0;
} 
