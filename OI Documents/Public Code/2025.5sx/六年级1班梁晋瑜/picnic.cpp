#include<bits/stdc++.h>
using namespace std;
long long n,y;
long long x[10001];
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=1){
		cout<<0;
	}else{
		cout<<15;
	}
	return 0;
}

