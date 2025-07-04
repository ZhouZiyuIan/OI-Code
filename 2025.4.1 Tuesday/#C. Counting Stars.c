#include<stdio.h>
const int MOD=1e9+7;
int n,k,r,fac[10000001],inv[10000001],tmp;
long long sum;
int fstpow(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
void pre(){
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n]=fstpow(fac[n],MOD-2);
	for(int i=n-1;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
}
inline int C(int m,int n){
	if(n<m)return 0;
	return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
main(){
	fac[0]=inv[0]=1;
	scanf("%d%d%d",&n,&k,&r);
	pre();
	tmp=k/r;
	for(int i=1;i<=tmp;i++)sum+=(i%2?1ll:-1ll)*C(i,n-k+1)%MOD*C(k-i*r,n-i*r)%MOD;
	printf("%lld",(sum%MOD+MOD)%MOD);
}