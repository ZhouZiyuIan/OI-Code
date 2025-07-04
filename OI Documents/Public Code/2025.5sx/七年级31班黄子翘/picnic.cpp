#include<bits/stdc++.h>
using namespace std;
int n,y,a[3000],as;
double ans[1000000];
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				ans[++as]=((a[i]-a[j])*y*1.0)/2;
			}
			if(a[j]>a[i]){
				ans[++as]=((a[j]-a[i])*y*1.0)/2;
			}
			for(int k=1;k<as;k++){
				if(ans[as]==ans[i]){
					as--;
					break;
				}
			}
		}
	}
	cout<<as;
}
