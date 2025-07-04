#include<stdio.h>
int n,m,a[501][501],sam,mx[501],dd[501][501],cur,max;
void sol(){
	cur=0;
	for(int i=1;i<n;i++){
		sam=0;
		for(int j=0;j<m;j++)if(a[0][j]==a[i][j]&&a[0][j])sam++;
		if(sam>=mx[i])cur++;
	}
	max<cur?max=cur:0;
}
main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		sam=0;
		for(int k=0;k<m;k++)if(a[j][k]&&a[i][k]==a[j][k])sam++;
		mx[j]<sam?mx[j]=sam:0;
		mx[i]<sam?mx[i]=sam:0;
		dd[j][i]=dd[i][j]=sam;
	}
	sol();
	for(int i=0;i<m;i++){
		if(a[0][i])continue;
		a[0][i]=1;
		sol();
		a[0][i]=0;
	}
	printf("%d",max);
}
