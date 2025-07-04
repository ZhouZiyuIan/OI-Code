#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,m,sum,a[MAXN],flg;
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(sum<m) sum+=a[i];
		else flg=1;
	}
	if(!flg) m%=sum;
	for(int i=1,x;i<=n;i++){
		x=a[i];
		if(x>=m){
			printf("%lld\n%lld",i,x-m);
			return 0;
		}
		m-=x;
	}
	return 0;
} 
