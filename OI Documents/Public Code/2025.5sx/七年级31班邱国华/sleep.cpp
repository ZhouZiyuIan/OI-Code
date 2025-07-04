#include<bits/stdc++.h>
using namespace std;
long long x[100000];
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>x[i];
	}
	for(int i=1;i<=a;i++){
		if(b>x[i]){
			b-=x[i];
		}else if(b==x[i]){
			cout<<i<<endl<<"0";
			exit(0);
		}else{
			cout<<i<<endl<<x[i]-b;
			exit(0);
		}
	}
}
