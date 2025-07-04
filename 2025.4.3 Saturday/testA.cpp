#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q,k,nx[5002][60],c[5002][60]; 
string S,T; 
signed main(){
	// freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>Q>>S>>T;
	for(int i=0;i<S.size();i++){
		int j=i,cnt=0;
		for(int k=0;k<T.size();k++)if(S[j]==T[k])if(++j==S.size())++cnt,j=0;
		nx[i][0]=j,c[i][0]=cnt;
	}
	for(int j=1;j<=59;j++)for(int i=0;i<S.size();i++)nx[i][j]=nx[nx[i][j-1]][j-1],c[i][j]=c[i][j-1]+c[nx[i][j-1]][j-1];
	while(Q--){
		cin>>k;
		int i=0,ans=1;
		for(int j=59;~j;j--)if(k>>j&1)ans+=c[i][j],i=nx[i][j];
		cout<<ans<<'\n';
	}
	system("pause");
}
