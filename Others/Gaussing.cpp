#include<stdio.h>
#include<math.h>
int n;
double a[101][102],temp;
int Gauss(int n,int m){
    int w=1;
    for(int i=1;i<=m;i++){
        int tmp=w;
        for(int j=w+1;j<=n;j++)if(abs(a[j][i])>fabs(a[tmp][i]))tmp=j;
        if(abs(a[tmp][i])<=1e-8)continue;
        for(int j=i;j<=m;j++)temp=a[w][j],a[w][j]=a[tmp][j],a[tmp][j]=temp;
        for(int j=m;j>=i;j--)a[w][j]/=a[w][i];
        for(int j=1;j<=n;j++){
            if(j==w)continue;
            for(int k=m;k>=i;k--)a[j][k]-=a[w][k]*a[j][i];
        }
        w++;
    }
    // printf("%lf",a[w-1][m-1]);
    if(abs(a[w-1][m-1])<=1e-8){
        printf("-1");
        return -1;
    }
    if(m-w>0){
        printf("0");
        return 1;
    }
    return 0;
}
main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)scanf("%lf",&a[i][j]);
    if(Gauss(n,n+1)!=0)return 0;
    for(int i=1;i<=n;i++)printf("x%d=%.2lf\n",i,a[i][n+1]);
}
/*
2
1 1 2
3 3 6
*/