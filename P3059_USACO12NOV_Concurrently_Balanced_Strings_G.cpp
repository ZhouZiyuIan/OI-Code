#include<bits/stdc++.h>
#pragma GCC optimize(2,3,"Ofast")
using namespace std;
using ll=long long;
int const maxn=50000;
int n;
int k;
int const inf=998244353;
struct Tree{
	int a[maxn+1];
	int s[maxn+1];
	stack<int>st;
	int pp[maxn+1];
}tr[11];
int dn[maxn+1];
int up[maxn+1];
int ans;
int cr[maxn+1];
signed main(){
	freopen("cbs.in","r",stdin);
//	freopen("cbs.out","w",stdout);
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++){
		tr[i].s[0]=n;
		for(int j=1;j<=n;j++){
			char in=getchar();
			while(in!='('&&in!=')'){
				in=getchar();
			}
			tr[i].a[j]=(in=='('?1:-1);
			tr[i].s[j]=tr[i].s[j-1]+tr[i].a[j];
			if(tr[i].a[j]==1){
				tr[i].st.push(j);
			}
			else{
				if(tr[i].st.empty()){
					continue;
				}
				tr[i].pp[tr[i].st.top()]=j;
				tr[i].pp[j]=tr[i].st.top();
				tr[i].st.pop();
			}
		}
	}
	for(int i=1;i<=n;i++){
		dn[i]=inf;
		up[i]=0;
		for(int j=1;j<=k;j++){
			up[i]=max(up[i],tr[j].pp[i]);
			dn[i]=min(dn[i],tr[j].pp[i]);
		}
	}
	for(int l=n;l>=1;l--){
		int mi=dn[l];
		int ma=up[l];
		for(int r=l;r<=n;r++){
			mi=min(mi,dn[r]);
			ma=max(ma,up[r]);
			if(cr[r]){
				continue;
			}
			if(ma>r){
				cr[r]=1;
				continue;
			}
			if(mi<l){
				break;
			}
			ans++;
		}
	}
	printf("%d",ans);
	
	
	return 0;
}
