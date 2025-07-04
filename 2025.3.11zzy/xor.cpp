#include<stdio.h>
int n,ans[100001];
main(){
	scanf("%d",&n);
	ans[0]=1;ans[1]=2;
	for(int i=2;i<=n;i++)ans[i]=ans[i-1]+ans[i-2],ans[i]%=1000000009;
	printf("%d",ans[n]);
}
