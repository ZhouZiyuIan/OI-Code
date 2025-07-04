#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
string s;
int k,len,sumpro;
char c='a';
struct Node{
	int sum;
	char pho;	
}cnt[26];
bool cmp(Node x,Node y){
	if(x.sum==y.sum) return x.pho<y.pho;
	else return x.sum<y.sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;len=s.size();
	cin>>k;
	if(k==len){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0;i<26;i++){
		cnt[i].pho=c;
		c++;
	}
	for(int i=0;i<len;i++){
		cnt[s[i]-'a'].sum++;
		if(cnt[s[i]-'a'].sum==1) sumpro++;
	}
	sort(cnt,cnt+26,cmp);
	int del=0,delsum=0;
	for(int i=0;i<26;i++){
		if(delsum+cnt[i].sum<=k && cnt[i].sum>0){
			cnt[i].sum=-1;
			del++;
		}
	}
	cout<<sumpro-del<<endl;
	if(sumpro-del==0) return 0;
//	cout<<sumpro<<endl<<del<<endl;
	for(int i=0;i<len;i++){
		if(cnt[s[i]='a'].sum==-1) continue;
		else cout<<s[i];
	}
	return 0;
}

