#include<stdio.h>
#include<utility>
#include<map>
using namespace std;
map<long long,pair<long long,long long> >tt;
inline long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
int z;
long long M,l_more,r_more,l_2,l_3;
void proc_more(){
    long long tmp;
    for(long long i=1ll;i<=2e6;i++){
        tmp=i*(i+1ll);
        for(long long j=i+2ll;j<=i+50ll;j++){
            tmp/=gcd(tmp,j);
            if(tmp>1e18/j)break;
            tmp*=j;
            if(!tt[tmp].first)tt[tmp]=make_pair(i,j);
        }
    }
}
inline void proc_2(long long M){
    long long mid,l=1ll,r=2e9;
    while(l<=r){
        mid=(l+r)>>1ll;
        if(mid*(mid+1)<=M)l=mid+1ll;
        else r=mid-1ll;
    }
    if(r*r+r!=M){
        l_2=9223372036854775807ll;
        return;
    }
    l_2=r;
}
int main(){
    scanf("%d",&z);
    proc_more();
    for(int i=0;i<z;i++){
        scanf("%lld",&M);
        proc_2(M);
        if(tt[M].first)printf("%lld %lld\n",tt[M].first,tt[M].second);
        else if(l_2!=9223372036854775807ll)printf("%lld %lld\n",l_2,l_2+1ll);
        else printf("NIE\n");
    }
}