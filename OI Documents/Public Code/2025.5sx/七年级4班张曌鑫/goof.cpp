#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	char n[1000001];
	long long vis[27];
	int k;
	cin>>n;
	cin>>k;
	if(k>=strlen(n)){
		cout<<0<<endl;
		return 0;
	}
	else{
		for(int i=0;i<strlen(n);i++){
			vis[int(n[i])-97]++;
		}
		sort(vis,vis+26);
		for(int i=0;i<26;i++){
			cout<<vis[i];
		}
	}
	 
}

