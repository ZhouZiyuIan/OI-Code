#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x[100005];
ll t,cnt;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d %lld",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	while(1){
		cnt=cnt==n? 1:cnt+1;
		if(t-x[cnt]<=0){
			printf("%lld \n%d",cnt,x[cnt]-t);
			return 0;
		}
		t-=x[cnt];
	}
}
