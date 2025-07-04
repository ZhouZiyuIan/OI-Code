#include<bits/stdc++.h>
#define ll long long
ll n,a[10000000],y;
using namespace std;
set<float> st;
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		//cout<<i<<" ";
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]!=0)
			st.insert((y*(a[j]-a[i]))/2.0);
			//cout<<(y*(a[j]-a[i]))/2.0<<endl;
			//for(auto p:st) cout<<"i:"<<i<<endl;
		}
	}//st.erase(0);
	cout<<st.size();
	return 0;
}
