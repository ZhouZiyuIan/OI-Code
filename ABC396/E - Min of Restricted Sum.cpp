#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<utility>
using namespace std;
typedef long long ll;
vector<int>v;
vector<pair<int,int> >g[200005];
ll n,m,x,y,z,a[200005],tmp;
bool vis[200005];
inline void dfs(ll x){
    vis[x]=1;
    v.push_back(x);
    for(auto [y,z]:g[x]){
        if(!vis[y]){
            a[y]=a[x]^z;
            dfs(y);
        }
        else if((a[x]^a[y])!=z){
            printf("-1");
            exit(0);
        }
    }
}
main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    for(ll i=1;i<=n;i++){
        if(vis[i])continue;
        v.clear();
        dfs(i);
        tmp=0;
        for(ll j=0;j<33;j++){
            ll c0=0,c1=0;
            for(auto k:v){
                c0+=((a[k]>>j&1)==0);
                c1+=(a[k]>>j&1);
            }
            if(c1>c0)tmp|=(1<<j);
        }
        for(auto j:v)a[j]^=tmp;
    }
    for(ll i=1;i<=n;i++)printf("%lld ",a[i]);
}