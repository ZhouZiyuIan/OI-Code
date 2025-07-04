#include<atcoder/fenwicktree>
#include<stdio.h>
#include<vector>
#define int long long
using namespace atcoder;
std::vector<int>g[200001];
fenwick_tree<int>f(200001);
int n,m,a[200001],ans,c1,c2;
main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)g[a[i]].push_back(i);
    for(int i=0;i<n;i++){
        ans+=f.sum(a[i]+1,m);
        f.add(a[i],1);
    }
    printf("%lld\n",ans);
    for(int i=1;i<m;i++){
        c1=c2=0;
        for(int j=0;j<g[m-i].size();j++){
            c1+=g[m-i][j]-j;
            c2+=n-1-g[m-i][j]-(g[m-i].size()-1-j);
        }
        ans+=c1-c2;
        printf("%lld\n",ans);
    }
}