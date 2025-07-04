//sleep (test 3)
#include<bits/stdc++.h>
using namespace std;
unsigned long long t,x[100005],y[100005],ans,d;
int n,flag;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		ans+=x[i];
		if(ans>=t&&flag==0){
			d=i;
			flag=1;
		}
	}if(d==0){
		d=n;
	}printf("%d\n",d);
	if(t<=ans){
		printf("%d",ans-t);
	}else{
		int k=t%ans;
		int i=1;
        while(k>=0){
        	k-=x[i];
        	i++;
		}printf("%d",x[d]+k);
	}
}
