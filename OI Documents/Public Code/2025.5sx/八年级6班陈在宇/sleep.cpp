#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3;
int n,x[N];
ll t,s;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		s+=x[i];
	}
	t%=s;
	if(!t){
		cout<<n<<"\n0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		t-=x[i];
		if(t<=0){
			cout<<i<<'\n'<<-t;
			return 0;
		}
	}
}

