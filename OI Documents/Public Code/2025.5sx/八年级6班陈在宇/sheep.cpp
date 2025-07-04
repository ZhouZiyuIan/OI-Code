#include<bits/stdc++.h>
using namespace std;
const int N=2003,P=1e9+7;
int n,a[N],s1,s2,f[N][N];
bool v[N];
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(~a[i])v[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			s1++;
			if(!v[i])s2++;
		}
	}
	f[1][0]=1;
	for(int i=2;i<=s1;i++){
		f[i][0]=1ll*f[i-1][0]*i%P;
		for(int j=1;j<=i;j++){
			f[i][j]=f[i][j-1]-f[i-1][j-1]+P;
			if(f[i][j]>=P)f[i][j]-=P;
		}
	}
	cout<<f[s1][s2];
}

