#include<bits/stdc++.h>
using namespace std;
int sum,sum1;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	int n,t,k=0;
	cin>>n>>t;
	int x[n];
	for(int i=1; i<=n; i++) {
		cin>>x[i];
	}
	for(int i=1; i<=n; i++) {
		sum+=x[i];
		if(sum>=t) {
			k++;
			if(k<=1) {
				cout<<i<<endl;
			}
			if(k<=1) {
				sum-=t;
				sum1=sum;
				sum=0;
			}
		}
		if(i==n) {
			cout<<sum1+sum;
			break;
		}

		if(sum<t&&i==n&&k>0) {
			cout<<i<<endl<<0;
		}
	}

	return 0;
}



