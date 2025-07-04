#include<stdio.h>
long long n,t,k;
long long sc(long long b,long long c){
    long long l=0,r=600000001,mid;
    while(r-l>1){
        mid=(l+r)>>1;
        if(3*mid*mid+b*mid+c<=0)l=mid;
        else r=mid;
    }
    if(3*l*l+b*l+c==0)return l;
    return 0;
}
main(){
    scanf("%llu",&n);
    for(long long i=1;i*i*i<=n;i++){
        if(n%i)continue;
        t=n/i;
        k=sc(3*i,i*i-t);
        if(k){
            printf("%lld %lld",k+i,k);
            return 0;
        }
    }
    puts("-1");
}