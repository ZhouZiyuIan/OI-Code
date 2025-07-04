#include<bits/stdc++.h>
using namespace std;
int k,ct,ans[30],vis[30],ctt;
int p[30];
string s;
struct node{
	int cnt;
	char id;
}a[30];
bool cmp(node x,node y){
	return x.cnt<y.cnt;
}
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	scanf("%d",&k);
	if(k>=s.size()){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(!vis[s[i]-'a']){
			vis[s[i]-'a']=1;
			a[++ct].id=s[i];
			p[s[i]-'a']=ct;
		}
		a[p[s[i]-'a']].cnt++;
	} 
	sort(a+1,a+1+ct,cmp);
	ctt=ct;
	for(int i=1;i<=ct&&k-a[i].cnt>=0;i++){
		k-=a[i].cnt;
		ans[a[i].id-'a']=1;
		ctt--;
	}
	printf("%d\n",ctt);
	for(int i=0;i<s.size();i++){
		if(ans[s[i]-'a']) continue;
		printf("%c",s[i]);
	}
	return 0;
}
