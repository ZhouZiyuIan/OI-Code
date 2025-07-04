#include<bits/stdc++.h>
using namespace std;
int n,a[10001],b[10001];
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			b[i]=i; 
		}else b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1&&a[i+i]!=-1&&i+i<=n){
			swap(a[i+i],b[i]);
		}
	}
	return 0;
}

