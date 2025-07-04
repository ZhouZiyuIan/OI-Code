#include<stdio.h>
long long n,q;
const int MOD=998244353;
main(){
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    while(q--)printf("%lld",n%MOD*(n-1)%MOD*(n-2)%MOD*(n-3)%MOD);
}