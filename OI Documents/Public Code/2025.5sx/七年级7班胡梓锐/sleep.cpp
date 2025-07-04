#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,Once,ModS;
ll a[1000000];
ll b[1000000];
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) b[i]=a[i];
		else b[i]=b[i-1]+a[i];
		//cout<<b[i]<<endl;
		Once+=a[i];
	}
	ModS=t%Once;
	//cout<<ModS;
	for(int i=1;i<=n;i++){
		if(b[i]<ModS&&ModS<=b[i+1]){
			cout<<i+1<<endl<<b[i+1]-ModS;
		}
	}
	return 0;
}

