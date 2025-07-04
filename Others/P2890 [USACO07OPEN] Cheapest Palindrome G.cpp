#include<stdio.h>
int min(int a,int b){return a<b?a:b;}
int n,m,c[255][3],x,y,f[2010][2010];
char s[2010],t[2];
main(){
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=0;i<n;i++){
        scanf("%s%d%d",t,&x,&y);
        c[t[0]][0]=x;
        c[t[0]][1]=y;
    }
    for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)f[i][j]=2147483647;
    for(int i=1;i<=m;i++)f[i][i]=0;
    for(int i=0;i<=m+1;i++)for(int j=0;j<i;j++)f[i][j]=0;
    for(int k=1;k<=m;k++)for(int i=1;k+i<=m;i++){
        int j=k+i;
        f[i][j]=min(f[i][j],f[i+1][j]+min(c[s[i]][0],c[s[i]][1]));
        f[i][j]=min(f[i][j],f[i][j-1]+min(c[s[j]][0],c[s[j]][1]));
        if(s[i]==s[j])f[i][j]=min(f[i][j],f[i+1][j-1]);
    }
    printf("%d",f[1][m]);
}