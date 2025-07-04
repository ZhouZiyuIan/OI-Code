#include<stdio.h>
const int MOD=1e9+7;
int n,m,k;
long long allans=1ll,f[1000001],sum[1000001];
main(){
//    freopen("spainting.in","r",stdin);
//    freopen("spainting.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        allans*=m;
        allans%=MOD;
    }
    f[0]=1;
    sum[0]=1;
    for(int i=1;i<=n;i++){
        if(i<k)f[i]=f[i-1]*m;
        else f[i]=(sum[i-1]-sum[i-k]+MOD)%MOD*(m-1);
        f[i]%=MOD;
        sum[i]=sum[i-1]+f[i];
    }
    printf("%lld",(allans-f[n]+MOD)%MOD);
}