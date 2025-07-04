#include<stdio.h>
#include<stdbool.h>
#include<vector>
using namespace std;
vector<int>curr;
#ifndef __cplusplus
#warning I do not know how to solve it
#endif
int n,a[1000001],ans,cur;
bool vis[1000001];
void dfs(int x,int tmp){
	if(x==n){
		ans<cur?ans=cur:0;
		printf("Current Maximum f:%d; Current f: %d; With the Sequence Position of: ",ans,cur);
		for(int i=0;i<curr.size();i++)printf("%d(%d) ",curr[i]+1,a[curr[i]]);
		putchar('\n');
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			cur+=tmp&a[i];
			curr.push_back(i);
			vis[i]=1;
			dfs(x+1,tmp&a[i]);
			curr.pop_back();
			cur-=tmp&a[i];
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("#B.Testout.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	dfs(0,-1);
	printf("%d",ans);
}
/*
0001
0010
0011
0100
*/
