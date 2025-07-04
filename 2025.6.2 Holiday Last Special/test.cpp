#include<stdio.h>
#include<vector>
using namespace std;
vector<int>oputval;
int vis[200001],n=8,hval,tot,cnt;
void dfs(){
	if(oputval.size()==n){
		printf("hpval:%d with ",hval);
		tot+=hval;
		cnt++;
		for(auto i:oputval)printf("%d ",i);
		putchar(10);
		return;
	}
	for(int i=1;i<n;i++)if(vis[i]==0){
		vis[i]=1;
		oputval.emplace_back(i);
		for(int j=i+1;j<=n;j++)if(vis[j]==0){
			if(((j+1)>>1)==((i+1)>>1))hval++;
			vis[j]=1;
			oputval.emplace_back(j);
			dfs();
			oputval.pop_back();
			vis[j]=0;
			if(((j+1)>>1)==((i+1)>>1))hval--;
		}
		oputval.pop_back();
		vis[i]=0;
	}
}
main(){
	dfs();
	printf("%d %d",tot,cnt);
}
