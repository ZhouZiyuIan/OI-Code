#include <bits/stdc++.h>
#define ll unsigned long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
ll n,t,x[N],ans,val,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
//	freopen("simpleA.in","r",stdin);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		sum+=x[i];
	}
	t=t%sum;
	if(t==0){
		cout<<n<<endl<<x[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		val=ans;
		ans+=x[i];
		if(ans>t){
			if(t-val==0) cout<<i-1;
			else cout<<i;
			cout<<endl<<t-val;
			return 0;	
		}
	}
	return 0;
}

