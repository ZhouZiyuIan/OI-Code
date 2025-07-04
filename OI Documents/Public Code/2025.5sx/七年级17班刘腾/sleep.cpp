#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,t,x[N],f[N];
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout)
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		f[i]=f[i-1]+x[i];
	}
	if(t%f[n]==0){
		printf("%lld\n0",n);
		return 0;
	}
	if(t<f[n]){
		for(int i=1;i<=n;i++){
			if(t==f[i]){
				printf("%lld\n%lld",i,0);
				return 0;
			}else if(t<f[i]){
				printf("%lld\n%lld",i,f[i]-t);
				return 0;
			}
		}
		return 0;
	}
	if(t>f[n]){
		int k=t%f[n];
		for(int i=1;i<=n;i++){
			if(k==f[i]){
				printf("%lld\n%lld",i,0);
				return 0;
			}else if(k<f[i]){
				printf("%lld\n%lld",i,f[i]-k);
				return 0;
			}
		}
		return 0;
	}
}
