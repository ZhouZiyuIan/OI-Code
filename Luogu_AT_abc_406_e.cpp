#include<stdio.h>
#include<utility>
#include<string.h>
using namespace std;
const long long MOD=998244353;
long long T,N,K,r[61],len,tot,f[61][61][61],ans[61][61][61];
void tib(){
    long long tmp=N;
    while(tmp){
        r[++len]=tmp&1;
        tmp>>=1;
    }
}
pair<long long,long long> dfs(long long x,long long lim,long long cnt){
    if(cnt>K)return{0,0};
    if(!x)return{cnt==K,0};
    if(!lim&&~f[K][x][cnt])return{f[K][x][cnt],ans[K][x][cnt]};
    long long tcnt=0,sum=0,clim=(lim?r[x]:1);
    for(long long i=0;i<=clim;i++){
        pair<long long,long long>tmp=dfs(x-1,lim&&i==clim,cnt+i);
        tcnt+=tmp.first;
        tcnt%=MOD;
        sum+=tmp.second+tmp.first*((i<<x-1)%MOD)%MOD;
        sum%=MOD;
    }
    if(!lim){
        f[K][x][cnt]=tcnt;
        ans[K][x][cnt]=sum;
    }
    return{tcnt,sum};
}
main(){
    memset(f,-1,sizeof(f));
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&N,&K);
        tot=len=0;
        tib();
        printf("%d",dfs(len,1,0).second);
        putchar(10);
    }
}