#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,t,mp3[100010],ans,sum;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>mp3[i];
		sum+=mp3[i];
	}
	if(sum==t){
		cout<<n<<"\n"<<0;
	}else{
		int T=t%sum;
		for(int k=0,i=1;i<=n;i++){
			k+=mp3[i];
			if(k>=T){
				cout<<i<<"\n";
				int ans=k-T;
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 9
1 2 3
*/
