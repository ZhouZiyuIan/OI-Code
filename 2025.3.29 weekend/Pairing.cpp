#include<stdio.h>
#include<math.h>
int temp,cnt,lst,vis[100001],n,m;
int min(int a,int b){
	return a<b?a:b;
}
int main(){
    scanf("%d%d",&n,&m);
    lst=min(n,m);
	for(int i=1;i<=lst;i++)if(vis[i]==0){
		cnt+=(int)sqrt(n/i)*(int)sqrt(m/i);
		if(i!=1&&(long long)i*i<=lst){
			for(long long j=i*i;j<=lst;j+=i*i){
//				printf("fake");
				vis[j]=1;
			}
		}
	} 
    printf("%d",cnt);
}
