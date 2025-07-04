#include<stdio.h>
#include<math.h>
const int MOD=1000000007;
int n,m,k,stat[5001],x,dp[5001],sum[5001];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)scanf("%d",&x),stat[x+1]=1,stat[x+2]=2;
	for(int i=0;i<k;i++)scanf("%d",&x),stat[x+1]=2,stat[x+2]=1;
	sum[0]=0;
    dp[1]=sum[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(stat[i]==0)dp[j]=sum[i-1];
            else if(stat[i]==1)dp[j]=((sum[i-1]-sum[j-1])%MOD+MOD)%MOD;
            else dp[j]=sum[j-1];
        }
        for(int j=1;j<=i;j++)sum[j]=(sum[j-1]+dp[j])%MOD;
    }
    printf("%d",sum[n]);
}