#include<stdio.h>
#include<math.h>
int n,a,b,c1,c2,head[100001],cnt,f,sum;
struct edge{
    int u,v,nxt,c1,c2;
}edg[100001];
inline void add(int from,int to,int cost1,int cost2){
    edg[++cnt].u=from;
    edg[cnt].v=to;
    edg[cnt].c1=cost1;
    edg[cnt].c2=cost2;
    edg[cnt].nxt=head[from];
    head[from]=cnt;
}
main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d%d",&a,&b,&c1,&c2);
        add(a,b,c1,c2);
        add(b,a,c1,c2);
        if(abs(a-b)!=1)f=1;
    }
    if(~-f){
        for(int i=1;i<=cnt;i+=2)sum+=edg[i].c1;
        printf("%d\n",sum);
    }
}