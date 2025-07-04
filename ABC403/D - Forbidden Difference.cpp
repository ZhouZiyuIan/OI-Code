#include<stdio.h>
int n,d,a,x[1000001],ans,dp[1000001][2];
int max(int a,int b){return a>b?a:b;}
main(){
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)scanf("%d",&a),x[a]++;
	for(int i=0;i<=1000000;i++){
		if(i<d){
			dp[i][0]=x[i];
			dp[i][1]=0;
		}
		else{
			dp[i][1]=max(dp[i-d][0],dp[i-d][1]);
			if(x[i])dp[i][0]=dp[i-d][1]+x[i];
		}
	}
	for(int i=0;i<=1000000;i++)if(i+d>1000000)ans+=max(dp[i][0],dp[i][1]);
	if(d)printf("%d",n-ans);
	else{
		ans=0;
		for(int i=0;i<=1000000;i++)if(x[i])ans++;
		printf("%d",n-ans);
	}
}