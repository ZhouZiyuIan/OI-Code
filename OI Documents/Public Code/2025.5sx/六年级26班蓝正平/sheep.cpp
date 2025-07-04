#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int n,a[2001],ans,ans1=1,zgs;
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==-1){
			ans++;
		}
	}
	zgs=ans-1;
	for(int i=1;i<=ans;i++){
		if(zgs!=0){
			ans1*=zgs;
			zgs--;
		}
	}
	cout<<ans1%N;
	return 0;
} 
