#include<bits/stdc++.h>
using namespace std;
double x[100000];
double xx[100000];
int c=0;
bool dfs(double a){
	for(int i=0;i<c;i++){
		if(xx[i]==a){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	long a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	for(int i=0;i<a;i++){
		for(int ii=0;ii<a;ii++){
			if(i==ii){
				continue;
			}
			if(x[i]!=0&&x[ii]!=0&&dfs(abs(x[i]-x[ii])*abs(b)/2)){
				xx[c]=abs(x[i]-x[ii])*abs(b)/2;
				c++;
			}
		}
	}
	cout<<c;
}
