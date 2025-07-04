#include<bits/stdc++.h>
using namespace std;
char s[1001];
int k,a[101],maxx=0,mx=0;
int main(){
//	freopen("goof.in","r",stdin);
//	freopen("goof.out","w",stdout);
	cin>>s>>k;
	int l=strlen(s);
	if(k>=l){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<l;i++){
		int sum=s[i];
		a[sum]++;
	}
	for(int i=0;i<l;i++){
		int sum=s[i];
		if(a[sum]>=k&&a[sum]>maxx){
			mx=sum;
			maxx=a[sum];
		}
	}
	if(maxx-k==0) cout<<1<<endl;
	else cout<<maxx-k<<endl;
	for(int i=0;i<maxx;i++) cout<<char(mx);
	return 0;
}

