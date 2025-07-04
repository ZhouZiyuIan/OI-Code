#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,y,x[10050];
set<int>s;
int fun(int a,int b){
	if(b>a)return(b-a)*y;
	if(b<a)return(a-b)*y;
}
signed main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&y);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	if(n==1){
		puts("0");
		return 0;
	}
	sort(x+1,x+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int k=fun(x[i],x[j]);
			s.insert(k);
		}
	}
	printf("%lld",s.size());
}
