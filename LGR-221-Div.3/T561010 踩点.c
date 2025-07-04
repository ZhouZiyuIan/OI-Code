#include<stdio.h>
long long n,T,l[100001],r[100001],s,i;
int max(int a,int b){return a>b?a:b;} 
main(){         
    scanf("%lld%lld",&n,&T);
    for(i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
    for(i=1;i<n;i++)s+=max(0,l[i+1]-r[i]-T);
    printf("%lld",s);
}
