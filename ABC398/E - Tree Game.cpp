#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int>g[101];
int n,u,v,a[101][101],len;
void dfs(int x,int p,int s,int d){
    if(d!=1&&(d&1))a[s][x]=1,len++;
    for(int i=0;i<g[x].size();i++)if(g[x][i]!=p)dfs(g[x][i],x,s,d+1);
}
void fun(){
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i][j]){
        a[i][j]=a[j][i]=0;
        printf("%d %d\n",i,j);
        fflush(stdout);
        scanf("%d%d",&u,&v);
        if(u==-1&&v==-1)exit(0);
        a[u][v]=a[v][u]=0;
    }
}
main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)dfs(i,-1,i,0);
    if((len/2)&1){
        puts("First");
        fun();
    }
    else{
        puts("Second");
        scanf("%d%d",&u,&v);
        if(u==-1&&v==-1)return 0;
        a[u][v]=a[v][u]=0;
        fun();
    }
    fflush(stdout);
}