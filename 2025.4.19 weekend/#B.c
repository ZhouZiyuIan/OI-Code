#include<stdio.h>
#include<stdbool.h>
int n,a[1000001],ans,cur;
bool vis[1000001];
void dfs(int x,int tmp){
	if(x==n){
		ans<cur?ans=cur:0;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			cur+=tmp&a[i];
			vis[i]=1;
			dfs(x+1,tmp&a[i]);
			cur-=tmp&a[i];
			vis[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	dfs(0,-1);
	printf("%d",ans);
}