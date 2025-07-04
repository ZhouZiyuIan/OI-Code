#include<bits/stdc++.h>
using namespace std;
unsigned long long t;
unsigned long long n,x,a[100001],ans,zsj;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	zsj=x%ans;
	for(int i=1;i<=n;i++){
		if(zsj>a[i]){
			zsj-=a[i];
		}else{
			cout<<i<<endl<<a[i]-zsj;
			return 0;
		}
	}
} 
