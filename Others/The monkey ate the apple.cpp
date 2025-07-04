#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>route[500001],tmp;
int n,k,x,cnt,head[500001],vis[500001];
struct edg{
	int nxt,to;
}e[500001];
struct node{
    int no,depth,step;
}nd[500001];
void add(int from,int to){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}
void dfs1(int x,int dep){
    tmp.push_back(x);
    route[x]=tmp;
    nd[x].depth=dep;
    nd[x].no=x;
    for(int i=head[x];i;i=e[i].nxt){
        if(vis[e[i].to])continue;
        vis[e[i].to]=1;
        dfs1(e[i].to,dep+1);
        vis[e[i].to]=0;
        tmp.pop_back();
    }
}
bool cmp1(node a,node b){
    if(a.depth!=b.depth)return a.depth>b.depth;
    return a.no<b.no;
}
bool cmp2(node a,node b){
    if(a.step!=b.step)return a.step>b.step;
    return a.no<b.no;
}
main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        add(i,x);
        add(x,i);
    }
    tmp.push_back(k);
    vis[k]=1;
    dfs1(k,0);
    sort(nd,nd+n,cmp1);
    for(int i=0;i<n;i++){
        for(int j=route[nd[i].no].size()-1;j;j--){
            if(vis[route[nd[i].no][j]])break;
            vis[route[nd[i].no][j]]=1;
            nd[i].step++;
        }
    }
    sort(nd,nd+n,cmp2);
    printf("%d\n",k);
    for(int i=0;i<n;i++){
        if(!nd[i].step)break;
        printf("%d\n",nd[i].no);
    }
}
