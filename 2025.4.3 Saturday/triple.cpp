#include<stdio.h>
int n,L,u,v,w,val[3001];
long long tmp,dis[3001][3001];
main(){
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1000000000;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=dis[v][u]=w;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
    for(int i=1;i<n-1;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<=n;k++){
        tmp=dis[i][j]+dis[j][k]+dis[k][i];
        tmp%=L;
        if(val[i]<tmp)val[i]=tmp;
        if(val[j]<tmp)val[j]=tmp;
        if(val[k]<tmp)val[k]=tmp;
    }
    for(int i=1;i<=n;i++)printf("%lld\n",val[i]);
}