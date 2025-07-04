#include<atcoder/dsu>
#include<stdio.h>
#include<utility>
using namespace std;
using namespace atcoder;
pair<int,pair<int,int>>a[200001];
int n,m,u,v,w,ans=(1<<30)-1;
main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        a[i]={u-1,make_pair(v-1,w)};
    }
    for(int i=29;i>-1;i--){
        ans^=1<<i;
        dsu d(n);
        for(pair<int,pair<int,int>>cur:a)if((ans|cur.second.second)==ans)d.merge(cur.first,cur.second.first);
        if(!d.same(0,n-1))ans|=1<<i;
    }
    printf("%lld",ans);
}