#include<stdio.h>
int n,m,ans,f[501][501];
char a[501][501];
main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	if(a[1][1]==a[n][m]){
		f[1][n]=1;
		for(int s=1;s<n;s++){
			for(int x1=n-1;x1>=0;x1--){
				for(int x2=0;x2<n;x2++){
					if(a[x1][s+2-x1]==a[x2][n*2-s-x2])f[x1][x2]=(f[x1-1][x2+1]+f[x1-1][x2]+f[x1][x2+1]+f[x1-1][x2+1]);
				}
			}
		}
		for(int i=0;i<n;i++)ans=(ans+f[i][i]);
	}
	printf("%d",ans);
}